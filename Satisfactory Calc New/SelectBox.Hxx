#pragma once

#ifndef _SELECT_BOX_HXX_
#define _SELECT_BOX_HXX_

#include <map>
#include <cmath>
#include <sstream>

#include "AsciiMap.Hxx"
#include "TextButton.Hxx"
#include "ISelectable.Hxx"
#include "IReplaceable.Hxx"
#include "ConsoleObject.Hxx"

// All definition of this class will be do in hether file
// Template class can't be definition in other files

template <class T>
class SelectBox :
	public ConsoleObject,
	public ISelectable, 
	public IReplaceable
{

private:

	
	unsigned sizeX = 0u;
	unsigned sizeY = 0u;

	int positionX = 0;
	int positionY = 0;

	bool isSelected = false;

	unsigned nowSelectedIndex = 0u;
	unsigned willSelectedIndex = 0u;
	unsigned maxOptionsStrLength = 0u;

	std::vector<TextButton*> OptionButtons;
	std::pair<T, std::string> nowSelectedElement;
	std::vector<std::pair<T, std::string>> elements;

	KeyGuides keyGuides;

	ISelectable* upper = nullptr;
	ISelectable* lower = nullptr;
	ISelectable* left  = nullptr;
	ISelectable* right = nullptr;

	ColorCode foregroundColor = Color::DefaultForegroundColor;
	ColorCode backgroundColor = Color::HilightedBackgroundColor;
	ColorCode selectedForegroundColor = Color::HilightedForegroundColor;
	ColorCode selectedBackgroundColor = Color::HilightedBackgroundColor;

	void rebuildKeyGuides() {
		keyGuides.clear();

		// Initialize Default Key Guides

		keyGuides.push_back({ Keys::SELECT, "Change Option" });
		if (upper) keyGuides.push_back({ Keys::UP,    "Go Up"    });
		if (lower) keyGuides.push_back({ Keys::DOWN,  "Go Down"  });
		if (left)  keyGuides.push_back({ Keys::LEFT,  "Go Left"  });
		if (right) keyGuides.push_back({ Keys::RIGHT, "Go Right" });
			

	}

	void rerenderUnSelected() {

		// throw if nowSelectedIndex is larger then Option's amount
		if (nowSelectedIndex >= elements.size()) {
			std::cerr << "SelectBox::rerenderUnSelected()" << std::endl;
			std::cerr << "Max index is " << elements.size();
			std::cerr << ", But try to select element in " << nowSelectedIndex;

			throw std::out_of_range("SelectBox::Make()");
		}

		Delete2DimDynamicArray(Object, sizeY);
		Delete2DimDynamicArray(ForegroundColor, sizeY);
		Delete2DimDynamicArray(BackgroundColor, sizeY);

		// Calculate object width by selected option's name
		// Add 2 because element will be " Element "
		sizeX = static_cast<unsigned>(nowSelectedElement.second.size()) + 2u; 
		sizeY = 1;

		// Initialize Render Buffer
		Object          = Make2DimDynamicArray(1, sizeX, ' ');
		ForegroundColor = Make2DimDynamicArray(1, sizeX, foregroundColor);
		BackgroundColor = Make2DimDynamicArray(1, sizeX, backgroundColor);

		for (int x = 0; x < nowSelectedElement.second.size(); x++) {
			Object[0][x + 1u] = nowSelectedElement.second[x];
		}

		for (auto& buttons : OptionButtons) {
			buttons->Render = false;
		}

	}

	void rerenderSelected() {
		
		if (nowSelectedIndex >= elements.size()) {
			std::cerr << "SelectBox::rerenderSelected()" << std::endl;
			std::cerr << "Max index is " << elements.size();
			std::cerr << ", But try to select element in " << nowSelectedIndex;

			throw std::out_of_range("SelectBox::Make()");
		}

		Delete2DimDynamicArray(Object, sizeY);
		Delete2DimDynamicArray(ForegroundColor, sizeY);
		Delete2DimDynamicArray(BackgroundColor, sizeY);

		Object          = Make2DimDynamicArray(1, sizeX, ' ');
		ForegroundColor = Make2DimDynamicArray(1, sizeX, Color::NoColor);
		BackgroundColor = Make2DimDynamicArray(1, sizeX, Color::NoColor);

		for (int x = 0; x < nowSelectedElement.second.size(); x++) {
			Object[0][x + 1u] = nowSelectedElement.second[x];
		}

		for (int x = 0; x < nowSelectedElement.second.size() + 2; x++) {
			BackgroundColor[0][x] = Color::HilightedForegroundColor;
			ForegroundColor[0][x] = Color::HilightedBackgroundColor;
		}

		for (auto& button : OptionButtons) {
			button->Render = true;
		}

	}

protected:


	void ConsoleObject::Initialize() {};
	void ConsoleObject::Update(ISelectable*& _selecting) {

		if (isSelected) {

			// Go Up & Down Logics
			if (KeyManager::GetKeyPressed(Keys::UP)) {
				int select = willSelectedIndex - 1;
				if (select < 0) select = static_cast<int>(OptionButtons.size() - 1);

				_selecting->UnSelect();
				_selecting = OptionButtons[select];
				_selecting->Select();

				willSelectedIndex = select;
				nowSelectedElement = elements[select];

				NeedUpdate = true;

				return;
			}

			if (KeyManager::GetKeyPressed(Keys::DOWN)) {
				int select = willSelectedIndex + 1;
				if (select >= OptionButtons.size()) select = 0;

				_selecting->UnSelect();
				_selecting = OptionButtons[select];
				_selecting->Select();

				willSelectedIndex = select;
				nowSelectedElement = elements[select];

				NeedUpdate = true;

				return;
			}

			// Selecting Logics
			if (KeyManager::GetKeyPressed(Keys::SELECT)) {

				_selecting = this;
				nowSelectedIndex = willSelectedIndex;
				rerenderUnSelected();
				Select();

				isSelected = false;
				NeedUpdate = true;

				return;
				
			}
			if (KeyManager::GetKeyPressed(Keys::BACK)) {

				_selecting->UnSelect();
				_selecting = OptionButtons[nowSelectedIndex];
				_selecting = this;

				willSelectedIndex = nowSelectedIndex;
				nowSelectedElement = elements[nowSelectedIndex];
				rerenderUnSelected();
				Select();

				isSelected = false;
				NeedUpdate = true;

				return;

			}
		}

		// Open Popup Logic
		if (_selecting == this) {
			if (KeyManager::GetKeyPressed(Keys::SELECT)) {

				_selecting = OptionButtons[nowSelectedIndex];
				_selecting->Select();

				rerenderSelected();

				isSelected = true;
				NeedUpdate = true;

				return;
			}
		}
	};

	void ISelectable::Select() {

		// Change Color of Element to Hilighted Color
		for (unsigned x = 0u; x < sizeX; x++) {
			ForegroundColor[0][x] = selectedForegroundColor;
			BackgroundColor[0][x] = selectedBackgroundColor;
		}
	}
	void ISelectable::UnSelect() {

		// Change Color of Element to Default Color
		for (unsigned x = 0u; x < sizeX; x++) {
			ForegroundColor[0][x] = foregroundColor;
			BackgroundColor[0][x] = backgroundColor;
		}
	}

public:

	virtual ~SelectBox() {};

	void Make(
		int _posX,
		int _posY,
		const std::vector<std::pair<T, std::string>>& _elements,
		std::map<int, std::vector<ConsoleObject*>>& _objects,
		int _layer,
		unsigned _defaultOption = 0
	) {

		for (auto& button : OptionButtons) {

			for (auto& layer : _objects) {
				auto iterator = std::find(layer.second.begin(), layer.second.end(), button);
				if (iterator != layer.second.end()) layer.second.erase(iterator);
			}

		}
		
		// throw if _defaultOption is larger then Option's amount
		if (_defaultOption >= _elements.size()) {
			std::cerr << "SelectBox::Make()" << std::endl;
			std::cerr << "Max index is " << _elements.size();
			std::cerr << ", But you set Default value to " << _defaultOption;

			throw std::out_of_range("SelectBox::Make()");
		}

		Delete2DimDynamicArray(Object, sizeY);
		Delete2DimDynamicArray(ForegroundColor, sizeY);
		Delete2DimDynamicArray(BackgroundColor, sizeY);

		positionX = _posX;
		positionY = _posY;
		sizeY     = 1u;

		nowSelectedIndex   = _defaultOption;
		nowSelectedElement = _elements[_defaultOption];
		elements           = _elements;
		willSelectedIndex  = _defaultOption;

		Object          = Make2DimDynamicArray(1, sizeX, ' ');
		ForegroundColor = Make2DimDynamicArray(1, sizeX, Color::DefaultForegroundColor);
		BackgroundColor = Make2DimDynamicArray(1, sizeX, Color::DefaultBackgroundColor);

		// Get Max Leght of options String
		for (auto& element : _elements) {
			if (element.second.size() > maxOptionsStrLength) {
				maxOptionsStrLength = static_cast<unsigned>(element.second.size());
			}
		}

		// Make Options to Button
		
		for (auto& button : OptionButtons) {
			delete button;
		}
		OptionButtons.clear();

		for (unsigned index = 0u; index < _elements.size(); index++) {

			TextButton* tempButton = new TextButton;

			std::string buttonStringTemps = elements[index].second;
			
			unsigned space = static_cast<unsigned>(maxOptionsStrLength - elements[index].second.size());
			for (unsigned s = 0; s < space; s++) {
				buttonStringTemps += ' ';
			}

			tempButton->SetBackgroundColor(Color::HilightedBackgroundColor);
			tempButton->SetSelectedBackgroundColor(Color::DefaultForegroundColor);
			tempButton->SetSelectedForegroundColor(Color::HilightedBackgroundColor);

			tempButton->AdditionalKeyGuides.push_back({ Keys::BACK, "Cancel"  });
			tempButton->AdditionalKeyGuides.push_back({ Keys::UP,   "Go Up"   });
			tempButton->AdditionalKeyGuides.push_back({ Keys::DOWN, "Go Down" });

			tempButton->Make(positionX, positionY + index + 1, buttonStringTemps, false);

			if (index == _defaultOption) {
				tempButton->Select();
			}


			tempButton->Render = false;

			OptionButtons.push_back(tempButton);
			rerenderUnSelected();
		}

		for (auto& button : OptionButtons) {
			_objects[_layer].push_back(button);
		}

		// Render Default
		rebuildKeyGuides();
		rerenderUnSelected();

		NeedUpdate = true;
	}

	T GetElement() {
		return nowSelectedElement.first;
	};

	void SetForegroundColor(ColorCode _color) { foregroundColor = _color; }
	void SetBackgroundColor(ColorCode _color) { backgroundColor = _color; }
	void SetSelectedForegroundColor(ColorCode _color) { selectedForegroundColor = _color; }
	void SetSelectedBackgroundColor(ColorCode _color) { selectedBackgroundColor = _color; }

	KeyGuides AdditionalKeyGuides;
	KeyGuides ISelectable::GetKeyGuides() const {
		
		// Add Original Key Guides and Additional key Gudie and return
		KeyGuides result;

		for (const auto& keyGuide : keyGuides) {
			result.push_back(keyGuide);
		}

		for (const auto& keyGuide : AdditionalKeyGuides) {
			result.push_back(keyGuide);
		}

		return result;
	};

	ISelectable* ISelectable::GetUpper() const { return upper; }
	ISelectable* ISelectable::GetLower() const { return lower; }
	ISelectable* ISelectable::GetLeft () const { return left;  }
	ISelectable* ISelectable::GetRight() const { return right; }

	void ISelectable::LinkUpper(ISelectable* _upper) {
		upper = _upper;
		rebuildKeyGuides();
		NeedUpdate = true;
	}
	void ISelectable::LinkLower(ISelectable* _lower) {
		lower = _lower;
		rebuildKeyGuides();
		NeedUpdate = true;
	}
	void ISelectable::LinkLeft(ISelectable* _left) {
		left = _left;
		rebuildKeyGuides();
		NeedUpdate = true;
	}
	void ISelectable::LinkRight(ISelectable* _right) {
		right = _right;
		rebuildKeyGuides();
		NeedUpdate = true;
	}

	void IReplaceable::SetPositionX(int _x) {
		positionX = _x;
		NeedUpdate = true;
	}
	void IReplaceable::SetPositionY(int _y) {
		positionY = _y;
		NeedUpdate = false;
	}

	unsigned ConsoleObject::GetSizeX() const { return sizeX; }
	unsigned ConsoleObject::GetSizeY() const { return sizeY; }

	int ConsoleObject::GetPositionX() const { return positionX; }
	int ConsoleObject::GetPositionY() const { return positionY; }


};


#endif