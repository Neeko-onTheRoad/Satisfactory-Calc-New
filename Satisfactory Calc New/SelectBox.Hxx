#pragma once

#ifndef _SELECT_BOX_HXX_
#define _SELECT_BOX_HXX_

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
	bool needToPopup = false;
	unsigned nowSelectedIndex = 0u;
	unsigned willSelectedIndex = 0u;
	unsigned maxOptionsStrLength = 0u;
	std::pair<T, std::string> nowSelected;
	std::vector<std::pair<T, std::string>> elements;

	KeyGuides keyGuides;

	ISelectable* upper = nullptr;
	ISelectable* lower = nullptr;
	ISelectable* left  = nullptr;
	ISelectable* right = nullptr;

	ColorCode foregroundColor = Color::DefaultForegroundColor;
	ColorCode backgroundColor = Color::DefaultBackgroundColor;
	ColorCode selectedForegroundColor = Color::HilightedForegroundColor;
	ColorCode selectedBackgroundColor = Color::HilightedBackgroundColor;

	void rebuildKeyGuides() {
		keyGuides.clear();

		// Initialize Default Key Guides
					keyGuides.push_back({ "Enter",      "Change Option" });
		if (upper) keyGuides.push_back({ "Arrow Up",    "Go Up"         });
		if (lower) keyGuides.push_back({ "Arrow Down",  "Go Down"       });
		if (left)  keyGuides.push_back({ "Arrow Left",  "Go Left"       });
		if (right) keyGuides.push_back({ "Arrow Right", "Go Right"      });
	}

	void rerenderUnSelected() {

		// throw if nowSelectedIndex is larger then Option's amount
		if (nowSelectedIndex >= elements.size()) {
			std::cerr << "SelectBox::rerenderUnSelected()" << std::endl
				<< "Max index is " << elements.size()
				<< ", But try to select element in " << nowSelectedIndex;

			throw std::out_of_range("SelectBox::Make()");
		}

		// Calculate object width by selected option's name
		// Add 2 because element will be " Element "
		sizeX = static_cast<unsigned>(nowSelected.second.size()) + 2u; 
		sizeY = 1;

		delete[] Object[0];
		delete[] ForegroundColor[0];
		delete[] BackgroundColor[0];

		delete[] Object;
		delete[] ForegroundColor;
		delete[] BackgroundColor;

		// Initialize Render Buffer
		Object          = Make2DimDynamicArray(1, sizeX, ' ');
		ForegroundColor = Make2DimDynamicArray(1, sizeX, Color::DefaultForegroundColor);
		BackgroundColor = Make2DimDynamicArray(1, sizeX, Color::DefaultBackgroundColor);

		for (int x = 0; x < nowSelected.second.size(); x++) {
			Object[0][x + 1u] = nowSelected.second[x];
		}

	}

	void rerenderSelected() {
		
		if (nowSelectedIndex >= elements.size()) {
			std::cerr << "SelectBox::rerenderSelected()" << std::endl
				      << "Max index is " << elements.size()
				      << ", But try to select element in " << nowSelectedIndex;

			throw std::out_of_range("SelectBox::Make()");
		}

		delete[] Object[0];
		delete[] ForegroundColor[0];
		delete[] BackgroundColor[0];

		delete[] Object;
		delete[] BackgroundColor;
		delete[] ForegroundColor;

		Object          = Make2DimDynamicArray(1, sizeX, ' ');
		ForegroundColor = Make2DimDynamicArray(1, sizeX, Color::NoColor);
		BackgroundColor = Make2DimDynamicArray(1, sizeX, Color::NoColor);

		for (int x = 0; x < nowSelected.second.size(); x++) {
			Object[0][x + 1u] = nowSelected.second[x];
		}

		for (int x = 0; x < nowSelected.second.size() + 2; x++) {
			BackgroundColor[0][x] = Color::HilightedForegroundColor;
			ForegroundColor[0][x] = Color::HilightedBackgroundColor;
		}

		for (auto& button : Options) {
			button->Render = true;
		}

	}

protected:


	void ConsoleObject::Initialize() {};
	void ConsoleObject::Update(ISelectable*& _selecting) {
		
		if (needToPopup) {
			_selecting = Options[nowSelectedIndex];
			_selecting->Select();

			needToPopup = false;
		}

		if (_selecting == this) {

			if (isSelected) {
				
			}

			else {
			
				if (KeyManager::GetKeyPressed(Keys::SELECT)) {
					isSelected = true;
					NeedUpdate = true;

					rerenderSelected();

					needToPopup = true;
				}
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

	std::vector<TextButton*> Options;
	virtual ~SelectBox() {};

	void Make(int _posX, int _posY, const std::vector<std::pair<T, std::string>>& _elements, unsigned _defaultOption = 0) {

		// throw if _defaultOption is larger then Option's amount
		if (_defaultOption >= _elements.size()) {
			std::cerr << "SelectBox::Make()" << std::endl
						<< "Max index is " << _elements.size()
						<< ", But you set Default value to " << _defaultOption;

			throw std::out_of_range("SelectBox::Make()");
		}

		positionX = _posX;
		positionY = _posY;
		sizeY     = 1u;


		nowSelectedIndex = _defaultOption;
		nowSelected = _elements[_defaultOption];
		elements = _elements;


		Object = Make2DimDynamicArray(1, sizeX, ' ');
		ForegroundColor = Make2DimDynamicArray(1, sizeX, Color::DefaultForegroundColor);
		BackgroundColor = Make2DimDynamicArray(1, sizeX, Color::DefaultBackgroundColor);

		// Get Max Leght of options String
		for (auto& element : _elements) {
			if (element.second.size() > maxOptionsStrLength) {
				maxOptionsStrLength = static_cast<unsigned>(element.second.size());
			}
		}

		// Make Options to Button
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
			tempButton->AdditionalKeyGuides.push_back({"Backspace", "Cancel"});
			tempButton->Make(positionX, positionY + index + 1, buttonStringTemps, false);


			tempButton->Render = false;

			Options.push_back(tempButton);
			rerenderUnSelected();
		}

		// Render Default
		rerenderUnSelected();

	}

	T GetElement() {
		return nowSelected.first;
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