#define CLAY_IMPLEMENTATION
#include "./clay/clay.h"

double windowWidth = 1024, windowHeight = 768;
float modelPageOneZRotation = 0;
uint32_t ACTIVE_RENDERER_INDEX = 0;

typedef struct
{
	void* memory;
	uintptr_t offset;
} Arena;

Arena frameArena = {};

typedef struct
{
	Clay_String link;
	bool cursorPointer;
	bool disablePointerEvents;
} CustomHTMLData;

CustomHTMLData*
FrameAllocateCustomData(CustomHTMLData data)
{
	CustomHTMLData *customData = (CustomHTMLData *)(frameArena.memory + frameArena.offset);
	*customData = data;
	frameArena.offset += sizeof(CustomHTMLData);
	return customData;
}

Clay_String*
FrameAllocateString(Clay_String string)
{
	Clay_String *allocated = (Clay_String *)(frameArena.memory + frameArena.offset);
	*allocated = string;
	frameArena.offset += sizeof(Clay_String);
	return allocated;
}


// TODO: Move to a seperate file
Clay_RenderCommandArray CreateLayout()
{
	Clay_BeginLayout();

	CLAY({
			.id = CLAY_ID("OuterContainer"),
			.layout =
			{
				.sizing = {
					CLAY_SIZING_GROW(0),
					CLAY_SIZING_GROW(0)
				}
			},
			.backgroundColor = {255, 0, 0, 255}
			}){}

	return Clay_EndLayout();
}

CLAY_WASM_EXPORT("SetScratchMemory")
void
SetScratchMemory(void * memory)
{
	frameArena.memory = memory;
}

CLAY_WASM_EXPORT("UpdateDrawFrame")
Clay_RenderCommandArray
UpdateDrawFrame
(
	float width,
	float height,
	float mouseWheelX,
	float mouseWheelY,
	float mousePositionX,
	float mousePositionY,
	bool isTouchDown,
	bool isMouseDown,
	bool arrowKeyDownPressedThisFrame,
	bool arrowKeyUpPressedThisFrame,
	bool dKeyPressedThisFrame,
	float deltaTime
)
{
	frameArena.offset = 0;
	//windowWidth = width;
	//windowHeight = height;

	Clay_SetLayoutDimensions((Clay_Dimensions) { width, height });
	
	
	return CreateLayout();
}

int main()
{
	return 0;
}
