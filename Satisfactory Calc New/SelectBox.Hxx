#pragma once

#ifndef _SELECT_BOX_HXX_
#define _SELECT_BOX_HXX_

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

	unsigned nowSelectedIndex = 0u;
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

	void selectElement(unsigned _index) {

		// throw if _index is larger then Option's amount
		if (_index >= elements.size()) {
			std::cerr << "SelectBox::Make()" << std::endl
				<< "Max index is " << elements.size()
				<< ", But try to select element in " << _index;

			throw std::out_of_range("SelectBox::Make()");
		}

		
		nowSelectedIndex = _index;
		nowSelected = elements[_index];

		// Calculate object width by selected option's name
		// Add 2 because element will be " Element "
		sizeX = static_cast<unsigned>(nowSelected.second.size()) + 2u; 

		// Initialize Render Buffer
		Object          = Make2DimDynamicArray(1, sizeX, ' ');
		ForegroundColor = Make2DimDynamicArray(1, sizeX, Color::DefaultForegroundColor);
		BackgroundColor = Make2DimDynamicArray(1, sizeX, Color::DefaultBackgroundColor);

		for (int x = 0; x < nowSelected.second.size(); x++) {
			Object[0][x + 1u] = nowSelected.second[x];
		}

	}

protected:

	void ConsoleObject::Initialize() {};
	void ConsoleObject::Update(ISelectable* _selecting) {};

	void ISelectable::Select() {

		// Change Color of Element to Hilighted Color
		for (unsigned x = 0u; x < sizeX; x++) {
			ForegroundColor[0][x] = selectedForegroundColor;
			BackgroundColor[0][x] = selectedForegroundColor;
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

	void Make(int _posX, int _posY, const std::vector<std::pair<T, std::string>>& _elements, unsigned _defaultOption = 0) {

		// throw if _defaultOption is larger then Option's amount
		if (_defaultOption >= _elements.size()) {
			std::cerr << "SelectBox::Make()" << std::endl
						<< "Max index is " << _elements.size()
						<< ", But you set Default value to " << _defaultOption;

			throw std::out_of_range("SelectBox::Make()");
		}

		elements = _elements;

		positionX = _posX;
		positionY = _posY;
		sizeY     = 1u;

		selectElement(_defaultOption);

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