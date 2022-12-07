#pragma once
#define SINGLETON(CLASS) public:static CLASS* Instance(){static CLASS singleClass; return &singleClass;}
enum class BRUSH_TYPE {
	HOLLOW,
	YELLOW,
	END
}; 
enum class PEN_TYPE {
	RED,
	GREEN,
	BLUE,
	END
};