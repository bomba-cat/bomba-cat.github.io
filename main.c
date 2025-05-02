#define CLAY_IMPLEMENTATION
#include "./clay/clay.h"

double windowWidth = 1024, windowHeight = 768;
float modelPageOneZRotation = 0;
uint32_t ACTIVE_RENDERER_INDEX = 0;

#define RAYLIB_VECTOR2_TO_CLAY_VECTOR2(vector) (Clay_Vector2) { .x = (vector).x, .y = (vector).y }

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
Clay_RenderCommandArray
CreateLayout()
{
	Clay_BeginLayout();

	CLAY
		({
			.id = CLAY_ID("OuterContainer"),
			.layout =
			{
				.sizing =
				{
					CLAY_SIZING_GROW(0),
					CLAY_SIZING_GROW(0)
				}
			},
			.backgroundColor = {245, 245, 245, 255}
			})
	{
		CLAY
			({
				.id = CLAY_ID("SigmaImage"),
				.layout =
				{
					.sizing = { CLAY_SIZING_FIXED(150) }
				},
				.image =
					{
						.sourceDimensions = { 1080, 2398 },
						.imageData = FrameAllocateString(CLAY_STRING("./images/sigma.png"))
					}
			 }){}
	}

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
	windowWidth = width;
	windowHeight = height;

	Clay_SetLayoutDimensions((Clay_Dimensions) { width, height });

	Clay_SetCullingEnabled(ACTIVE_RENDERER_INDEX == 1);
  Clay_SetExternalScrollHandlingEnabled(ACTIVE_RENDERER_INDEX == 0);
	
	return CreateLayout();
}

int main()
{
	return 0;
}
