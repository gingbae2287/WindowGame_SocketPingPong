#pragma once
#define SINGLETON(CLASS) public:static CLASS* Instance(){static CLASS singleClass; return &singleClass;}

#define BUTTON_CREATEROOM 10001
enum class BRUSH_TYPE {
	HOLLOW,
	YELLOW,
	BLACK,
	END
}; 
enum class PEN_TYPE {
	HOLLOW,
	RED,
	GREEN,
	BLUE,
	END
};

enum ColliderType {
	BOX,
	CIRCLE,
};

enum SCENE_TYPE {
	START,
	GAME,
	END,
};