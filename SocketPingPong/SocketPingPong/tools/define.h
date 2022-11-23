#pragma once
#define SINGLETON(CLASS) public:static CLASS* Instance(){static CLASS singleClass; return &singleClass;}
enum class BRUSH_TYPE {
	HOLLOW,
	END
}; 
enum class PEN_TYPE {
	RED,
	GREEN,
	BLUE,
	END
};