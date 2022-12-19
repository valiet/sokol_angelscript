
#include <assert.h>  // assert()
#include <string.h>  // strstr()

#include "cangelscript.h"

#define SOKOL_IMPL
#define SOKOL_GLCORE33
#include "sokol_app.h"
#include "sokol_gfx.h"
#include "sokol_time.h"
#include "sokol_audio.h"
#include "sokol_fetch.h"
#include "sokol_glue.h"

int32_t sokol_time_angelscript_module_native(asIScriptEngine* engine) {
    int r = 0;
    r = asEngine_RegisterGlobalFunction(engine, "void stm_setup()", stm_setup, asCALL_CDECL, NULL);  assert(r >= 0);
    r = asEngine_RegisterGlobalFunction(engine, "uint64 stm_now()", stm_now, asCALL_CDECL, NULL);  assert(r >= 0);
    r = asEngine_RegisterGlobalFunction(engine, "uint64 stm_diff(uint64 new_ticks, uint64 old_ticks)", stm_diff, asCALL_CDECL, NULL);  assert(r >= 0);
    r = asEngine_RegisterGlobalFunction(engine, "uint64 stm_since(uint64 start_ticks)", stm_since, asCALL_CDECL, NULL);  assert(r >= 0);
    r = asEngine_RegisterGlobalFunction(engine, "uint64 stm_laptime(uint64 &inout last_time)", stm_laptime, asCALL_CDECL, NULL);  assert(r >= 0);
    r = asEngine_RegisterGlobalFunction(engine, "uint64 stm_round_to_common_refresh_rate(uint64 frame_ticks)", stm_round_to_common_refresh_rate, asCALL_CDECL, NULL);  assert(r >= 0);
    r = asEngine_RegisterGlobalFunction(engine, "double stm_sec(uint64 ticks)", stm_sec, asCALL_CDECL, NULL);  assert(r >= 0);
    r = asEngine_RegisterGlobalFunction(engine, "double stm_ms(uint64 ticks)", stm_ms, asCALL_CDECL, NULL);  assert(r >= 0);
    r = asEngine_RegisterGlobalFunction(engine, "double stm_us(uint64 ticks)", stm_us, asCALL_CDECL, NULL);  assert(r >= 0);
    r = asEngine_RegisterGlobalFunction(engine, "double stm_ns(uint64 ticks)", stm_ns, asCALL_CDECL, NULL);  assert(r >= 0);
    return r;
}

int32_t sokol_app_angelscript_module_native(asIScriptEngine* engine) {
    if (sizeof(int) == sizeof(int64_t)) {
        asEngine_RegisterTypedef(engine, "nint", "int64");
        asEngine_RegisterTypedef(engine, "nuint", "uint64");
    }
    else {
        asEngine_RegisterTypedef(engine, "nint", "int");
        asEngine_RegisterTypedef(engine, "nuint", "uint");
    }
    int r = 0;
    r = asEngine_RegisterEnum(engine, "sapp_event_type");  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_event_type", "SAPP_EVENTTYPE_INVALID", SAPP_EVENTTYPE_INVALID);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_event_type", "SAPP_EVENTTYPE_KEY_DOWN", SAPP_EVENTTYPE_KEY_DOWN);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_event_type", "SAPP_EVENTTYPE_KEY_UP", SAPP_EVENTTYPE_KEY_UP);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_event_type", "SAPP_EVENTTYPE_CHAR", SAPP_EVENTTYPE_CHAR);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_event_type", "SAPP_EVENTTYPE_MOUSE_DOWN", SAPP_EVENTTYPE_MOUSE_DOWN);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_event_type", "SAPP_EVENTTYPE_MOUSE_UP", SAPP_EVENTTYPE_MOUSE_UP);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_event_type", "SAPP_EVENTTYPE_MOUSE_SCROLL", SAPP_EVENTTYPE_MOUSE_SCROLL);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_event_type", "SAPP_EVENTTYPE_MOUSE_MOVE", SAPP_EVENTTYPE_MOUSE_MOVE);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_event_type", "SAPP_EVENTTYPE_MOUSE_ENTER", SAPP_EVENTTYPE_MOUSE_ENTER);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_event_type", "SAPP_EVENTTYPE_MOUSE_LEAVE", SAPP_EVENTTYPE_MOUSE_LEAVE);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_event_type", "SAPP_EVENTTYPE_TOUCHES_MOVED", SAPP_EVENTTYPE_TOUCHES_MOVED);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_event_type", "SAPP_EVENTTYPE_TOUCHES_ENDED", SAPP_EVENTTYPE_TOUCHES_ENDED);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_event_type", "SAPP_EVENTTYPE_TOUCHES_CANCELLED", SAPP_EVENTTYPE_TOUCHES_CANCELLED);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_event_type", "SAPP_EVENTTYPE_RESIZED", SAPP_EVENTTYPE_RESIZED);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_event_type", "SAPP_EVENTTYPE_ICONIFIED", SAPP_EVENTTYPE_ICONIFIED);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_event_type", "SAPP_EVENTTYPE_RESTORED", SAPP_EVENTTYPE_RESTORED);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_event_type", "SAPP_EVENTTYPE_FOCUSED", SAPP_EVENTTYPE_FOCUSED);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_event_type", "SAPP_EVENTTYPE_UNFOCUSED", SAPP_EVENTTYPE_UNFOCUSED);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_event_type", "SAPP_EVENTTYPE_SUSPENDED", SAPP_EVENTTYPE_SUSPENDED);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_event_type", "SAPP_EVENTTYPE_RESUMED", SAPP_EVENTTYPE_RESUMED);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_event_type", "SAPP_EVENTTYPE_QUIT_REQUESTED", SAPP_EVENTTYPE_QUIT_REQUESTED);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_event_type", "SAPP_EVENTTYPE_CLIPBOARD_PASTED", SAPP_EVENTTYPE_CLIPBOARD_PASTED);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_event_type", "SAPP_EVENTTYPE_FILES_DROPPED", SAPP_EVENTTYPE_FILES_DROPPED);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_event_type", "_SAPP_EVENTTYPE_NUM", _SAPP_EVENTTYPE_NUM);  assert(r >= 0);
   
    r = asEngine_RegisterEnum(engine, "sapp_keycode");  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_INVALID", SAPP_KEYCODE_INVALID);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_SPACE", SAPP_KEYCODE_SPACE);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_APOSTROPHE", SAPP_KEYCODE_APOSTROPHE);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_COMMA", SAPP_KEYCODE_COMMA);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_MINUS", SAPP_KEYCODE_MINUS);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_PERIOD", SAPP_KEYCODE_PERIOD);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_SLASH", SAPP_KEYCODE_SLASH);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_0", SAPP_KEYCODE_0);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_1", SAPP_KEYCODE_1);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_2", SAPP_KEYCODE_2);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_3", SAPP_KEYCODE_3);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_4", SAPP_KEYCODE_4);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_5", SAPP_KEYCODE_5);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_6", SAPP_KEYCODE_6);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_7", SAPP_KEYCODE_7);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_8", SAPP_KEYCODE_8);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_9", SAPP_KEYCODE_9);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_SEMICOLON", SAPP_KEYCODE_SEMICOLON);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_EQUAL", SAPP_KEYCODE_EQUAL);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_A", SAPP_KEYCODE_A);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_B", SAPP_KEYCODE_B);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_C", SAPP_KEYCODE_C);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_D", SAPP_KEYCODE_D);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_E", SAPP_KEYCODE_E);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_F", SAPP_KEYCODE_F);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_G", SAPP_KEYCODE_G);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_H", SAPP_KEYCODE_H);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_I", SAPP_KEYCODE_I);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_J", SAPP_KEYCODE_J);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_K", SAPP_KEYCODE_K);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_L", SAPP_KEYCODE_L);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_M", SAPP_KEYCODE_M);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_N", SAPP_KEYCODE_N);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_O", SAPP_KEYCODE_O);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_P", SAPP_KEYCODE_P);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_Q", SAPP_KEYCODE_Q);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_R", SAPP_KEYCODE_R);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_S", SAPP_KEYCODE_S);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_T", SAPP_KEYCODE_T);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_U", SAPP_KEYCODE_U);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_V", SAPP_KEYCODE_V);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_W", SAPP_KEYCODE_W);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_X", SAPP_KEYCODE_X);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_Y", SAPP_KEYCODE_Y);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_Z", SAPP_KEYCODE_Z);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_LEFT_BRACKET", SAPP_KEYCODE_LEFT_BRACKET);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_BACKSLASH", SAPP_KEYCODE_BACKSLASH);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_RIGHT_BRACKET", SAPP_KEYCODE_RIGHT_BRACKET);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_GRAVE_ACCENT", SAPP_KEYCODE_GRAVE_ACCENT);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_WORLD_1", SAPP_KEYCODE_WORLD_1);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_WORLD_2", SAPP_KEYCODE_WORLD_2);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_ESCAPE", SAPP_KEYCODE_ESCAPE);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_ENTER", SAPP_KEYCODE_ENTER);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_TAB", SAPP_KEYCODE_TAB);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_BACKSPACE", SAPP_KEYCODE_BACKSPACE);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_INSERT", SAPP_KEYCODE_INSERT);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_DELETE", SAPP_KEYCODE_DELETE);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_RIGHT", SAPP_KEYCODE_RIGHT);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_LEFT", SAPP_KEYCODE_LEFT);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_DOWN", SAPP_KEYCODE_DOWN);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_UP", SAPP_KEYCODE_UP);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_PAGE_UP", SAPP_KEYCODE_PAGE_UP);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_PAGE_DOWN", SAPP_KEYCODE_PAGE_DOWN);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_HOME", SAPP_KEYCODE_HOME);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_END", SAPP_KEYCODE_END);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_CAPS_LOCK", SAPP_KEYCODE_CAPS_LOCK);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_SCROLL_LOCK", SAPP_KEYCODE_SCROLL_LOCK);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_NUM_LOCK", SAPP_KEYCODE_NUM_LOCK);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_PRINT_SCREEN", SAPP_KEYCODE_PRINT_SCREEN);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_PAUSE", SAPP_KEYCODE_PAUSE);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_F1", SAPP_KEYCODE_F1);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_F2", SAPP_KEYCODE_F2);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_F3", SAPP_KEYCODE_F3);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_F4", SAPP_KEYCODE_F4);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_F5", SAPP_KEYCODE_F5);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_F6", SAPP_KEYCODE_F6);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_F7", SAPP_KEYCODE_F7);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_F8", SAPP_KEYCODE_F8);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_F9", SAPP_KEYCODE_F9);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_F10", SAPP_KEYCODE_F10);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_F11", SAPP_KEYCODE_F11);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_F12", SAPP_KEYCODE_F12);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_F13", SAPP_KEYCODE_F13);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_F14", SAPP_KEYCODE_F14);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_F15", SAPP_KEYCODE_F15);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_F16", SAPP_KEYCODE_F16);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_F17", SAPP_KEYCODE_F17);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_F18", SAPP_KEYCODE_F18);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_F19", SAPP_KEYCODE_F19);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_F20", SAPP_KEYCODE_F20);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_F21", SAPP_KEYCODE_F21);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_F22", SAPP_KEYCODE_F22);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_F23", SAPP_KEYCODE_F23);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_F24", SAPP_KEYCODE_F24);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_F25", SAPP_KEYCODE_F25);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_KP_0", SAPP_KEYCODE_KP_0);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_KP_1", SAPP_KEYCODE_KP_1);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_KP_2", SAPP_KEYCODE_KP_2);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_KP_3", SAPP_KEYCODE_KP_3);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_KP_4", SAPP_KEYCODE_KP_4);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_KP_5", SAPP_KEYCODE_KP_5);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_KP_6", SAPP_KEYCODE_KP_6);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_KP_7", SAPP_KEYCODE_KP_7);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_KP_8", SAPP_KEYCODE_KP_8);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_KP_9", SAPP_KEYCODE_KP_9);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_KP_DECIMAL", SAPP_KEYCODE_KP_DECIMAL);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_KP_DIVIDE", SAPP_KEYCODE_KP_DIVIDE);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_KP_MULTIPLY", SAPP_KEYCODE_KP_MULTIPLY);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_KP_SUBTRACT", SAPP_KEYCODE_KP_SUBTRACT);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_KP_ADD", SAPP_KEYCODE_KP_ADD);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_KP_ENTER", SAPP_KEYCODE_KP_ENTER);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_KP_EQUAL", SAPP_KEYCODE_KP_EQUAL);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_LEFT_SHIFT", SAPP_KEYCODE_LEFT_SHIFT);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_LEFT_CONTROL", SAPP_KEYCODE_LEFT_CONTROL);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_LEFT_ALT", SAPP_KEYCODE_LEFT_ALT);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_LEFT_SUPER", SAPP_KEYCODE_LEFT_SUPER);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_RIGHT_SHIFT", SAPP_KEYCODE_RIGHT_SHIFT);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_RIGHT_CONTROL", SAPP_KEYCODE_RIGHT_CONTROL);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_RIGHT_ALT", SAPP_KEYCODE_RIGHT_ALT);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_RIGHT_SUPER", SAPP_KEYCODE_RIGHT_SUPER);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_keycode", "SAPP_KEYCODE_MENU", SAPP_KEYCODE_MENU);  assert(r >= 0);

    r = asEngine_RegisterObjectType(engine, "sapp_touchpoint", sizeof(sapp_touchpoint), asOBJ_VALUE | asOBJ_POD);  assert(r >= 0);
    r = asEngine_RegisterObjectProperty(engine, "sapp_touchpoint", "uint identifier", offsetof(sapp_touchpoint, identifier)); assert(r >= 0);
    r = asEngine_RegisterObjectProperty(engine, "sapp_touchpoint", "float pos_x", offsetof(sapp_touchpoint, pos_x)); assert(r >= 0);
    r = asEngine_RegisterObjectProperty(engine, "sapp_touchpoint", "float pos_y", offsetof(sapp_touchpoint, pos_y)); assert(r >= 0);
    r = asEngine_RegisterObjectProperty(engine, "sapp_touchpoint", "bool changed", offsetof(sapp_touchpoint, changed)); assert(r >= 0);

    r = asEngine_RegisterEnum(engine, "sapp_mousebutton");  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_mousebutton", "SAPP_MOUSEBUTTON_LEFT", SAPP_MOUSEBUTTON_LEFT);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_mousebutton", "SAPP_MOUSEBUTTON_RIGHT", SAPP_MOUSEBUTTON_RIGHT);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_mousebutton", "SAPP_MOUSEBUTTON_MIDDLE", SAPP_MOUSEBUTTON_MIDDLE);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_mousebutton", "SAPP_MOUSEBUTTON_INVALID", SAPP_MOUSEBUTTON_INVALID);  assert(r >= 0);

    r = asEngine_RegisterEnum(engine, "sapp_modifier");  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_modifier", "SAPP_MODIFIER_SHIFT", SAPP_MODIFIER_SHIFT);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_modifier", "SAPP_MODIFIER_CTRL", SAPP_MODIFIER_CTRL);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_modifier", "SAPP_MODIFIER_ALT", SAPP_MODIFIER_ALT);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_modifier", "SAPP_MODIFIER_SUPER", SAPP_MODIFIER_SUPER);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_modifier", "SAPP_MODIFIER_LMB", SAPP_MODIFIER_LMB);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_modifier", "SAPP_MODIFIER_RMB", SAPP_MODIFIER_RMB);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_modifier", "SAPP_MODIFIER_MMB", SAPP_MODIFIER_MMB);  assert(r >= 0);

    r = asEngine_RegisterObjectType(engine, "sapp_event", sizeof(sapp_event), asOBJ_VALUE | asOBJ_POD);  assert(r >= 0);
    r = asEngine_RegisterObjectProperty(engine, "sapp_event", "uint64 frame_count", offsetof(sapp_event, frame_count)); assert(r >= 0);
    r = asEngine_RegisterObjectProperty(engine, "sapp_event", "sapp_event_type type", offsetof(sapp_event, type)); assert(r >= 0);
    r = asEngine_RegisterObjectProperty(engine, "sapp_event", "sapp_keycode key_code", offsetof(sapp_event, key_code)); assert(r >= 0);
    r = asEngine_RegisterObjectProperty(engine, "sapp_event", "bool char_code", offsetof(sapp_event, char_code)); assert(r >= 0);
    r = asEngine_RegisterObjectProperty(engine, "sapp_event", "bool key_repeat", offsetof(sapp_event, key_repeat)); assert(r >= 0);
    r = asEngine_RegisterObjectProperty(engine, "sapp_event", "sapp_modifier modifiers", offsetof(sapp_event, modifiers)); assert(r >= 0);
    r = asEngine_RegisterObjectProperty(engine, "sapp_event", "sapp_mousebutton mouse_button", offsetof(sapp_event, mouse_button)); assert(r >= 0);
    r = asEngine_RegisterObjectProperty(engine, "sapp_event", "float mouse_x", offsetof(sapp_event, mouse_x)); assert(r >= 0);
    r = asEngine_RegisterObjectProperty(engine, "sapp_event", "float mouse_y", offsetof(sapp_event, mouse_y)); assert(r >= 0);
    r = asEngine_RegisterObjectProperty(engine, "sapp_event", "float mouse_dx", offsetof(sapp_event, mouse_dx)); assert(r >= 0);
    r = asEngine_RegisterObjectProperty(engine, "sapp_event", "float mouse_dy", offsetof(sapp_event, mouse_dy)); assert(r >= 0);
    r = asEngine_RegisterObjectProperty(engine, "sapp_event", "float scroll_x", offsetof(sapp_event, scroll_x)); assert(r >= 0);
    r = asEngine_RegisterObjectProperty(engine, "sapp_event", "float scroll_y", offsetof(sapp_event, scroll_y)); assert(r >= 0);
    r = asEngine_RegisterObjectProperty(engine, "sapp_event", "nint window_width", offsetof(sapp_event, window_width)); assert(r >= 0);
    r = asEngine_RegisterObjectProperty(engine, "sapp_event", "nint window_height", offsetof(sapp_event, window_height)); assert(r >= 0);
    r = asEngine_RegisterObjectProperty(engine, "sapp_event", "nint framebuffer_width", offsetof(sapp_event, framebuffer_width)); assert(r >= 0);
    r = asEngine_RegisterObjectProperty(engine, "sapp_event", "nint framebuffer_height", offsetof(sapp_event, framebuffer_height)); assert(r >= 0);
    r = asEngine_RegisterObjectProperty(engine, "sapp_event", "nint num_touches", offsetof(sapp_event, num_touches)); assert(r >= 0);
    r = asEngine_RegisterObjectProperty(engine, "sapp_event", "sapp_touchpoint touches0", offsetof(sapp_event, touches[0])); assert(r >= 0);
    r = asEngine_RegisterObjectProperty(engine, "sapp_event", "sapp_touchpoint touches1", offsetof(sapp_event, touches[1])); assert(r >= 0);
    r = asEngine_RegisterObjectProperty(engine, "sapp_event", "sapp_touchpoint touches2", offsetof(sapp_event, touches[2])); assert(r >= 0);
    r = asEngine_RegisterObjectProperty(engine, "sapp_event", "sapp_touchpoint touches3", offsetof(sapp_event, touches[3])); assert(r >= 0);
    r = asEngine_RegisterObjectProperty(engine, "sapp_event", "sapp_touchpoint touches4", offsetof(sapp_event, touches[4])); assert(r >= 0);
    r = asEngine_RegisterObjectProperty(engine, "sapp_event", "sapp_touchpoint touches5", offsetof(sapp_event, touches[5])); assert(r >= 0);
    r = asEngine_RegisterObjectProperty(engine, "sapp_event", "sapp_touchpoint touches6", offsetof(sapp_event, touches[6])); assert(r >= 0);
    r = asEngine_RegisterObjectProperty(engine, "sapp_event", "sapp_touchpoint touches7", offsetof(sapp_event, touches[7])); assert(r >= 0);

    r = asEngine_RegisterEnum(engine, "sapp_mouse_cursor");  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_mouse_cursor", "SAPP_MOUSECURSOR_DEFAULT", SAPP_MOUSECURSOR_DEFAULT);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_mouse_cursor", "SAPP_MOUSECURSOR_ARROW", SAPP_MOUSECURSOR_ARROW);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_mouse_cursor", "SAPP_MOUSECURSOR_IBEAM", SAPP_MOUSECURSOR_IBEAM);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_mouse_cursor", "SAPP_MOUSECURSOR_CROSSHAIR", SAPP_MOUSECURSOR_CROSSHAIR);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_mouse_cursor", "SAPP_MOUSECURSOR_POINTING_HAND", SAPP_MOUSECURSOR_POINTING_HAND);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_mouse_cursor", "SAPP_MOUSECURSOR_RESIZE_EW", SAPP_MOUSECURSOR_RESIZE_EW);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_mouse_cursor", "SAPP_MOUSECURSOR_RESIZE_NS", SAPP_MOUSECURSOR_RESIZE_NS);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_mouse_cursor", "SAPP_MOUSECURSOR_RESIZE_NWSE", SAPP_MOUSECURSOR_RESIZE_NWSE);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_mouse_cursor", "SAPP_MOUSECURSOR_RESIZE_NESW", SAPP_MOUSECURSOR_RESIZE_NESW);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_mouse_cursor", "SAPP_MOUSECURSOR_RESIZE_ALL", SAPP_MOUSECURSOR_RESIZE_ALL);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_mouse_cursor", "SAPP_MOUSECURSOR_NOT_ALLOWED", SAPP_MOUSECURSOR_NOT_ALLOWED);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sapp_mouse_cursor", "_SAPP_MOUSECURSOR_NUM", _SAPP_MOUSECURSOR_NUM);  assert(r >= 0);


    r = asEngine_RegisterGlobalFunction(engine, "bool sapp_isvalid()", sapp_isvalid, asCALL_CDECL, NULL);  assert(r >= 0);
    r = asEngine_RegisterGlobalFunction(engine, "nint sapp_width()", sapp_width, asCALL_CDECL, NULL);  assert(r >= 0);
    r = asEngine_RegisterGlobalFunction(engine, "float sapp_widthf()", sapp_widthf, asCALL_CDECL, NULL);  assert(r >= 0);
    r = asEngine_RegisterGlobalFunction(engine, "nint sapp_height()", sapp_height, asCALL_CDECL, NULL);  assert(r >= 0);
    r = asEngine_RegisterGlobalFunction(engine, "float sapp_heightf()", sapp_heightf, asCALL_CDECL, NULL);  assert(r >= 0);
    r = asEngine_RegisterGlobalFunction(engine, "nint sapp_color_format()", sapp_color_format, asCALL_CDECL, NULL);  assert(r >= 0);
    r = asEngine_RegisterGlobalFunction(engine, "nint sapp_depth_format()", sapp_depth_format, asCALL_CDECL, NULL);  assert(r >= 0);
    r = asEngine_RegisterGlobalFunction(engine, "nint sapp_sample_count()", sapp_sample_count, asCALL_CDECL, NULL);  assert(r >= 0);
    r = asEngine_RegisterGlobalFunction(engine, "bool sapp_high_dpi()", sapp_high_dpi, asCALL_CDECL, NULL);  assert(r >= 0);
    r = asEngine_RegisterGlobalFunction(engine, "float sapp_dpi_scale()", sapp_dpi_scale, asCALL_CDECL, NULL);  assert(r >= 0);
    r = asEngine_RegisterGlobalFunction(engine, "void sapp_show_keyboard(bool show)", sapp_show_keyboard, asCALL_CDECL, NULL);  assert(r >= 0);
    r = asEngine_RegisterGlobalFunction(engine, "bool sapp_keyboard_shown()", sapp_keyboard_shown, asCALL_CDECL, NULL);  assert(r >= 0);
    r = asEngine_RegisterGlobalFunction(engine, "bool sapp_is_fullscreen()", sapp_is_fullscreen, asCALL_CDECL, NULL);  assert(r >= 0);
    r = asEngine_RegisterGlobalFunction(engine, "void sapp_toggle_fullscreen()", sapp_toggle_fullscreen, asCALL_CDECL, NULL);  assert(r >= 0);
    r = asEngine_RegisterGlobalFunction(engine, "void sapp_show_mouse(bool show)", sapp_show_mouse, asCALL_CDECL, NULL);  assert(r >= 0);
    r = asEngine_RegisterGlobalFunction(engine, "bool sapp_mouse_shown()", sapp_mouse_shown, asCALL_CDECL, NULL);  assert(r >= 0);
    r = asEngine_RegisterGlobalFunction(engine, "void sapp_lock_mouse(bool lock)", sapp_lock_mouse, asCALL_CDECL, NULL);  assert(r >= 0);
    r = asEngine_RegisterGlobalFunction(engine, "bool sapp_mouse_locked()", sapp_mouse_locked, asCALL_CDECL, NULL);  assert(r >= 0);
    r = asEngine_RegisterGlobalFunction(engine, "void sapp_set_mouse_cursor(sapp_mouse_cursor cursor)", sapp_set_mouse_cursor, asCALL_CDECL, NULL);  assert(r >= 0);
    r = asEngine_RegisterGlobalFunction(engine, "sapp_mouse_cursor sapp_get_mouse_cursor()", sapp_get_mouse_cursor, asCALL_CDECL, NULL);  assert(r >= 0);
//    r = asEngine_RegisterGlobalFunction(engine, "void* sapp_userdata()", sapp_userdata, asCALL_CDECL, NULL);  assert(r >= 0);
//    r = asEngine_RegisterGlobalFunction(engine, "sapp_desc sapp_query_desc()", sapp_query_desc, asCALL_CDECL, NULL);  assert(r >= 0);
    r = asEngine_RegisterGlobalFunction(engine, "void sapp_request_quit()", sapp_request_quit, asCALL_CDECL, NULL);  assert(r >= 0);
    r = asEngine_RegisterGlobalFunction(engine, "void sapp_cancel_quit()", sapp_cancel_quit, asCALL_CDECL, NULL);  assert(r >= 0);
    r = asEngine_RegisterGlobalFunction(engine, "void sapp_quit()", sapp_quit, asCALL_CDECL, NULL);  assert(r >= 0);
    r = asEngine_RegisterGlobalFunction(engine, "void sapp_consume_event()", sapp_consume_event, asCALL_CDECL, NULL);  assert(r >= 0);
    r = asEngine_RegisterGlobalFunction(engine, "uint64 sapp_frame_count()", sapp_frame_count, asCALL_CDECL, NULL);  assert(r >= 0);
    r = asEngine_RegisterGlobalFunction(engine, "double sapp_frame_duration()", sapp_frame_duration, asCALL_CDECL, NULL);  assert(r >= 0);
//    r = asEngine_RegisterGlobalFunction(engine, "void sapp_set_clipboard_string(const char* str)", sapp_set_clipboard_string, asCALL_CDECL, NULL);  assert(r >= 0);
//    r = asEngine_RegisterGlobalFunction(engine, "const char* sapp_get_clipboard_string()", sapp_get_clipboard_string, asCALL_CDECL, NULL);  assert(r >= 0);
//    r = asEngine_RegisterGlobalFunction(engine, "void sapp_set_window_title(const char* str)", sapp_set_window_title, asCALL_CDECL, NULL);  assert(r >= 0);
//    r = asEngine_RegisterGlobalFunction(engine, "void sapp_set_icon(const sapp_icon_desc* icon_desc)", sapp_set_icon, asCALL_CDECL, NULL);  assert(r >= 0);
    r = asEngine_RegisterGlobalFunction(engine, "nint sapp_get_num_dropped_files()", sapp_get_num_dropped_files, asCALL_CDECL, NULL);  assert(r >= 0);
//    r = asEngine_RegisterGlobalFunction(engine, "const char* sapp_get_dropped_file_path(nint index)", sapp_get_dropped_file_path, asCALL_CDECL, NULL);  assert(r >= 0);

    r = asEngine_RegisterGlobalFunction(engine, "bool sapp_gles2()", sapp_gles2, asCALL_CDECL, NULL);  assert(r >= 0);

    r = asEngine_RegisterGlobalFunction(engine, "void sapp_html5_ask_leave_site(bool ask)", sapp_html5_ask_leave_site, asCALL_CDECL, NULL);  assert(r >= 0);
    r = asEngine_RegisterGlobalFunction(engine, "uint32 sapp_html5_get_dropped_file_size(nint index)", sapp_html5_get_dropped_file_size, asCALL_CDECL, NULL);  assert(r >= 0);
//    r = asEngine_RegisterGlobalFunction(engine, "void sapp_html5_fetch_dropped_file(const sapp_html5_fetch_request* request)", sapp_html5_fetch_dropped_file, asCALL_CDECL, NULL);  assert(r >= 0);

    return r;
}

int32_t sokol_gfx_angelscript_module_native(asIScriptEngine * engine) {

    if (sizeof(int) == sizeof(int64_t)) {
        asEngine_RegisterTypedef(engine, "nint", "int64");
        asEngine_RegisterTypedef(engine, "nuint", "uint64");
    }
    else {
        asEngine_RegisterTypedef(engine, "nint", "int");
        asEngine_RegisterTypedef(engine, "nuint", "uint");
    }
   
    int r = 0;
    r = asEngine_RegisterObjectType(engine, "sg_buffer", sizeof(sg_buffer), asOBJ_VALUE | asOBJ_POD);  assert( r >= 0 );
    r = asEngine_RegisterObjectProperty(engine, "sg_buffer", "uint32 id", offsetof(sg_buffer, id)); assert( r >= 0 );
    r = asEngine_RegisterObjectType(engine, "sg_image", sizeof(sg_image), asOBJ_VALUE | asOBJ_POD);  assert(r >= 0);
    r = asEngine_RegisterObjectProperty(engine, "sg_image", "uint32 id", offsetof(sg_image, id)); assert(r >= 0);
    r = asEngine_RegisterObjectType(engine, "sg_shader", sizeof(sg_shader), asOBJ_VALUE | asOBJ_POD);  assert(r >= 0);
    r = asEngine_RegisterObjectProperty(engine, "sg_shader", "uint32 id", offsetof(sg_shader, id)); assert(r >= 0);
    r = asEngine_RegisterObjectType(engine, "sg_pipeline", sizeof(sg_pipeline), asOBJ_VALUE | asOBJ_POD);  assert(r >= 0);
    r = asEngine_RegisterObjectProperty(engine, "sg_pipeline", "uint32 id", offsetof(sg_pipeline, id)); assert(r >= 0);
    r = asEngine_RegisterObjectType(engine, "sg_pass", sizeof(sg_pass), asOBJ_VALUE | asOBJ_POD);  assert(r >= 0);
    r = asEngine_RegisterObjectProperty(engine, "sg_pass", "uint32 id", offsetof(sg_pass, id)); assert(r >= 0);
    r = asEngine_RegisterObjectType(engine, "sg_context", sizeof(sg_context), asOBJ_VALUE | asOBJ_POD);  assert(r >= 0);
    r = asEngine_RegisterObjectProperty(engine, "sg_context", "uint32 id", offsetof(sg_context, id)); assert(r >= 0);

    r = asEngine_RegisterObjectType(engine, "sg_color", sizeof(sg_color), asOBJ_VALUE | asOBJ_POD);  assert(r >= 0);
    r = asEngine_RegisterObjectProperty(engine, "sg_color", "float r", offsetof(sg_color, r)); assert(r >= 0);
    r = asEngine_RegisterObjectProperty(engine, "sg_color", "float g", offsetof(sg_color, g)); assert(r >= 0);
    r = asEngine_RegisterObjectProperty(engine, "sg_color", "float b", offsetof(sg_color, b)); assert(r >= 0);
    r = asEngine_RegisterObjectProperty(engine, "sg_color", "float a", offsetof(sg_color, a)); assert(r >= 0);

    r = asEngine_RegisterEnum(engine, "sg_action");  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sg_action", "_SG_ACTION_DEFAULT", _SG_ACTION_DEFAULT);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sg_action", "SG_ACTION_CLEAR", SG_ACTION_CLEAR);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sg_action", "SG_ACTION_LOAD", SG_ACTION_LOAD);  assert(r >= 0);
    r = asEngine_RegisterEnumValue(engine, "sg_action", "SG_ACTION_DONTCARE", SG_ACTION_DONTCARE);  assert(r >= 0);

    r = asEngine_RegisterObjectType(engine, "sg_color_attachment_action", sizeof(sg_color_attachment_action), asOBJ_VALUE | asOBJ_POD);  assert(r >= 0);
    r = asEngine_RegisterObjectProperty(engine, "sg_color_attachment_action", "sg_action action", offsetof(sg_color_attachment_action, action)); assert(r >= 0);
    r = asEngine_RegisterObjectProperty(engine, "sg_color_attachment_action", "sg_color value", offsetof(sg_color_attachment_action, value)); assert(r >= 0);

    r = asEngine_RegisterObjectType(engine, "sg_depth_attachment_action", sizeof(sg_depth_attachment_action), asOBJ_VALUE | asOBJ_POD);  assert(r >= 0);
    r = asEngine_RegisterObjectProperty(engine, "sg_depth_attachment_action", "sg_action action", offsetof(sg_depth_attachment_action, action)); assert(r >= 0);
    r = asEngine_RegisterObjectProperty(engine, "sg_depth_attachment_action", "float value", offsetof(sg_depth_attachment_action, value)); assert(r >= 0);

    r = asEngine_RegisterObjectType(engine, "sg_stencil_attachment_action", sizeof(sg_stencil_attachment_action), asOBJ_VALUE | asOBJ_POD);  assert(r >= 0);
    r = asEngine_RegisterObjectProperty(engine, "sg_stencil_attachment_action", "sg_action action", offsetof(sg_stencil_attachment_action, action)); assert(r >= 0);
    r = asEngine_RegisterObjectProperty(engine, "sg_stencil_attachment_action", "uint8 value", offsetof(sg_stencil_attachment_action, value)); assert(r >= 0);

    r = asEngine_RegisterObjectType(engine, "sg_pass_action", sizeof(sg_pass_action), asOBJ_VALUE | asOBJ_POD);  assert(r >= 0);
    r = asEngine_RegisterObjectProperty(engine, "sg_pass_action", "sg_action action", offsetof(sg_pass_action, depth)); assert(r >= 0);
    r = asEngine_RegisterObjectProperty(engine, "sg_pass_action", "uint8 value", offsetof(sg_pass_action, stencil)); assert(r >= 0);
    r = asEngine_RegisterObjectProperty(engine, "sg_pass_action", "sg_color_attachment_action color0", offsetof(sg_pass_action, colors[0])); assert(r >= 0);
    r = asEngine_RegisterObjectProperty(engine, "sg_pass_action", "sg_color_attachment_action color1", offsetof(sg_pass_action, colors[1])); assert(r >= 0);
    r = asEngine_RegisterObjectProperty(engine, "sg_pass_action", "sg_color_attachment_action color2", offsetof(sg_pass_action, colors[2])); assert(r >= 0);
    r = asEngine_RegisterObjectProperty(engine, "sg_pass_action", "sg_color_attachment_action color3", offsetof(sg_pass_action, colors[3])); assert(r >= 0);
  
    /* setup and misc functions */
//    r = asEngine_RegisterGlobalFunction(engine, "void sg_setup(sg_desc@+)", sg_setup , asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "void sg_shutdown()", sg_shutdown , asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "bool sg_isvalid()", sg_isvalid , asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "void sg_reset_state_cache()", sg_reset_state_cache , asCALL_CDECL, NULL);  assert( r >= 0 );
//    r = asEngine_RegisterGlobalFunction(engine, "sg_trace_hooks sg_install_trace_hooks(sg_trace_hooks@+)",sg_install_trace_hooks , asCALL_CDECL, NULL);  assert( r >= 0 );
//    r = asEngine_RegisterGlobalFunction(engine, "void sg_push_debug_group(const char* name)", sg_push_debug_group, asCALL_CDECL, NULL);  assert( r >= 0 );
//    r = asEngine_RegisterGlobalFunction(engine, "void sg_pop_debug_group()", sg_pop_debug_group , asCALL_CDECL, NULL);  assert( r >= 0 );

    /* resource creation, destruction and updating */
//     r = asEngine_RegisterGlobalFunction(engine, "sg_buffer sg_make_buffer(const sg_buffer_desc@+)", sg_make_buffer , asCALL_CDECL, NULL);  assert( r >= 0 );
//     r = asEngine_RegisterGlobalFunction(engine, "sg_image sg_make_image(const sg_image_desc@+)", sg_make_image , asCALL_CDECL, NULL);  assert( r >= 0 );
//     r = asEngine_RegisterGlobalFunction(engine, "sg_shader sg_make_shader(const sg_shader_desc@+)", sg_make_shader , asCALL_CDECL, NULL);  assert( r >= 0 );
//     r = asEngine_RegisterGlobalFunction(engine, "sg_pipeline sg_make_pipeline(const sg_pipeline_desc@+)", sg_make_pipeline , asCALL_CDECL, NULL);  assert( r >= 0 );
//     r = asEngine_RegisterGlobalFunction(engine, "sg_pass sg_make_pass(const sg_pass_desc@+)", sg_make_pass , asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "void sg_destroy_buffer(sg_buffer buf)", sg_destroy_buffer , asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "void sg_destroy_image(sg_image img)", sg_destroy_image , asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "void sg_destroy_shader(sg_shader shd)", sg_destroy_shader , asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "void sg_destroy_pipeline(sg_pipeline pip)", sg_destroy_pipeline , asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "void sg_destroy_pass(sg_pass pass)", sg_destroy_pass , asCALL_CDECL, NULL);  assert( r >= 0 );
//     r = asEngine_RegisterGlobalFunction(engine, "void sg_update_buffer(sg_buffer buf, const sg_range@+)", sg_update_buffer , asCALL_CDECL, NULL);  assert( r >= 0 );
//     r = asEngine_RegisterGlobalFunction(engine, "void sg_update_image(sg_image img, const sg_image_data@+)", sg_update_image , asCALL_CDECL, NULL);  assert( r >= 0 );
//     r = asEngine_RegisterGlobalFunction(engine, "nint sg_append_buffer(sg_buffer buf, const sg_range@+)", sg_append_buffer , asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "bool sg_query_buffer_overflow(sg_buffer buf)", sg_query_buffer_overflow , asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "bool sg_query_buffer_will_overflow(sg_buffer buf, size_t size)", sg_query_buffer_will_overflow , asCALL_CDECL, NULL);  assert( r >= 0 );

    /* rendering functions */
    r = asEngine_RegisterGlobalFunction(engine, "void sg_begin_default_pass(const sg_pass_action@+, nint width, nint height)", sg_begin_default_pass , asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "void sg_begin_default_passf(const sg_pass_action@+, float width, float height)", sg_begin_default_passf , asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "void sg_begin_pass(sg_pass pass, const sg_pass_action@+)", sg_begin_pass , asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "void sg_apply_viewport(nint x, nint y, nint width, nint height, bool origin_top_left)", sg_apply_viewport , asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "void sg_apply_viewportf(float x, float y, float width, float height, bool origin_top_left)", sg_apply_viewportf , asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "void sg_apply_scissor_rect(nint x, nint y, nint width, nint height, bool origin_top_left)", sg_apply_scissor_rect , asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "void sg_apply_scissor_rectf(float x, float y, float width, float height, bool origin_top_left)", sg_apply_scissor_rectf , asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "void sg_apply_pipeline(sg_pipeline pip)", sg_apply_pipeline , asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "void sg_apply_bindings(const sg_bindings@+)", sg_apply_bindings , asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "void sg_apply_uniforms(sg_shader_stage stage, nint ub_index, const sg_range@+)", sg_apply_uniforms , asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "void sg_draw(nint base_element, nint num_elements, nint num_instances)", sg_draw , asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "void sg_end_pass()", sg_end_pass , asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "void sg_commit()", sg_commit , asCALL_CDECL, NULL);  assert( r >= 0 );

    /* getting information */
    r = asEngine_RegisterGlobalFunction(engine, "sg_desc sg_query_desc()", sg_query_desc , asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "sg_backend sg_query_backend()", sg_query_backend , asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "sg_features sg_query_features()", sg_query_features , asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "sg_limits sg_query_limits()", sg_query_limits , asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "sg_pixelformat_info sg_query_pixelformat(sg_pixel_format fmt)", sg_query_pixelformat , asCALL_CDECL, NULL);  assert( r >= 0 );
    /* get current state of a resource (INITIAL, ALLOC, VALID, FAILED, INVALID) */
    r = asEngine_RegisterGlobalFunction(engine, "sg_resource_state sg_query_buffer_state(sg_buffer buf)", sg_query_buffer_state , asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "sg_resource_state sg_query_image_state(sg_image img)", sg_query_image_state , asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "sg_resource_state sg_query_shader_state(sg_shader shd)", sg_query_shader_state , asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "sg_resource_state sg_query_pipeline_state(sg_pipeline pip)", sg_query_pipeline_state , asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "sg_resource_state sg_query_pass_state(sg_pass pass)", sg_query_pass_state , asCALL_CDECL, NULL);  assert( r >= 0 );
    /* get runtime information about a resource */
    r = asEngine_RegisterGlobalFunction(engine, "sg_buffer_info sg_query_buffer_info(sg_buffer buf)", sg_query_buffer_info , asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "sg_image_info sg_query_image_info(sg_image img)", sg_query_image_info , asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "sg_shader_info sg_query_shader_info(sg_shader shd)", sg_query_shader_info  , asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "sg_pipeline_info sg_query_pipeline_info(sg_pipeline pip)", sg_query_pipeline_info , asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "sg_pass_info sg_query_pass_info(sg_pass pass)", sg_query_pass_info , asCALL_CDECL, NULL);  assert( r >= 0 );
    /* get resource creation desc struct with their default values replaced */
    r = asEngine_RegisterGlobalFunction(engine, "sg_buffer_desc sg_query_buffer_defaults(const sg_buffer_desc@+)", sg_query_buffer_defaults , asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "sg_image_desc sg_query_image_defaults(const sg_image_desc@+)", sg_query_image_defaults , asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "sg_shader_desc sg_query_shader_defaults(const sg_shader_desc@+)", sg_query_shader_defaults , asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "sg_pipeline_desc sg_query_pipeline_defaults(const sg_pipeline_desc@+)", sg_query_pipeline_defaults , asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "sg_pass_desc sg_query_pass_defaults(const sg_pass_desc@+)", sg_query_pass_defaults , asCALL_CDECL, NULL);  assert( r >= 0 );

    /* separate resource allocation and initialization (for async setup) */
    r = asEngine_RegisterGlobalFunction(engine, "sg_buffer sg_alloc_buffer()", sg_alloc_buffer , asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "sg_image sg_alloc_image()", sg_alloc_image , asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "sg_shader sg_alloc_shader()", sg_alloc_shader , asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "sg_pipeline sg_alloc_pipeline()", sg_alloc_pipeline , asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "sg_pass sg_alloc_pass()", sg_alloc_pass , asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "void sg_dealloc_buffer(sg_buffer buf_id)", sg_dealloc_buffer , asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "void sg_dealloc_image(sg_image img_id)", sg_dealloc_image , asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "void sg_dealloc_shader(sg_shader shd_id)", sg_dealloc_shader , asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "void sg_dealloc_pipeline(sg_pipeline pip_id)", sg_dealloc_pipeline , asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "void sg_dealloc_pass(sg_pass pass_id)", sg_dealloc_pass , asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "void sg_init_buffer(sg_buffer buf_id, const sg_buffer_desc @+)", sg_init_buffer , asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "void sg_init_image(sg_image img_id, const sg_image_desc @+)", sg_init_image , asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "void sg_init_shader(sg_shader shd_id, const sg_shader_desc @+)", sg_init_shader  , asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "void sg_init_pipeline(sg_pipeline pip_id, const sg_pipeline_desc @+)", sg_init_pipeline , asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "void sg_init_pass(sg_pass pass_id, const sg_pass_desc @+)",sg_init_pass, asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "bool sg_uninit_buffer(sg_buffer buf_id)",sg_uninit_buffer, asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "bool sg_uninit_image(sg_image img_id)", sg_uninit_image , asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "bool sg_uninit_shader(sg_shader shd_id)", sg_uninit_shader , asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "bool sg_uninit_pipeline(sg_pipeline pip_id)", sg_uninit_pipeline , asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "bool sg_uninit_pass(sg_pass pass_id)", sg_uninit_pass , asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "void sg_fail_buffer(sg_buffer buf_id)", sg_fail_buffer , asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "void sg_fail_image(sg_image img_id)", sg_fail_image , asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "void sg_fail_shader(sg_shader shd_id)", sg_fail_shader , asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "void sg_fail_pipeline(sg_pipeline pip_id)", sg_fail_pipeline , asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "void sg_fail_pass(sg_pass pass_id)", sg_fail_pass , asCALL_CDECL, NULL);  assert( r >= 0 );

    /* rendering contexts (optional) */
    r = asEngine_RegisterGlobalFunction(engine, "sg_context sg_setup_context()", sg_setup_context , asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "void sg_activate_context(sg_context ctx_id)",  sg_activate_context, asCALL_CDECL, NULL);  assert( r >= 0 );
    r = asEngine_RegisterGlobalFunction(engine, "void sg_discard_context(sg_context ctx_id)", sg_discard_context , asCALL_CDECL, NULL);  assert( r >= 0 );
    return r;
}




static struct 
{
    asIScriptEngine* engine;
    asIScriptContext* context;
    asIScriptModule* module;

    asIScriptFunction* call_init;
    asIScriptFunction* call_fini;
    asIScriptFunction* call_step;

} _state;



static void 
angelscript_message_callback(const asSMessageInfo* msg, void* param) {
    const char* type = "";
    switch (msg->type) {
    case asMSGTYPE_ERROR: type = "ERROR"; break;
    case asMSGTYPE_WARNING: type = "WARN"; break;
    case asMSGTYPE_INFORMATION: type = "INFO"; break;
    }
    fprintf(stderr, "%s (%d, %d) : %s : %s\n", msg->section, msg->row, msg->col, type, msg->message);
}

static void 
main_init(void) {
    int r = 0;
    fprintf(stdout, "Angelscript %s\n", asGetLibraryVersion());
    fprintf(stdout, "   options %s\n", asGetLibraryOptions());

    _state.engine = asCreateScriptEngine(ANGELSCRIPT_VERSION); assert(_state.engine != 0);
    asEngine_SetMessageCallback( _state.engine, angelscript_message_callback, 0, asCALL_CDECL);
//    asEngine_SetEngineProperty( _state.engine,asEP_AUTO_GARBAGE_COLLECT, 0);
    asEngine_SetEngineProperty( _state.engine,asEP_USE_CHARACTER_LITERALS, 1); //to have 'c' mean a single char
    asEngine_SetEngineProperty( _state.engine,asEP_ALLOW_MULTILINE_STRINGS, 1);
    asEngine_SetEngineProperty(_state.engine, asEP_ALLOW_UNSAFE_REFERENCES, 1);

    sokol_time_angelscript_module_native(_state.engine);

    _state.context = asEngine_RequestContext(_state.engine); assert(_state.context != 0);

    _state.module = asEngine_GetModule(_state.engine, "script", asGM_ALWAYS_CREATE); assert(_state.module != 0);

    r = asModule_AddScriptSection(_state.module, "", 
        "uint64 testvalue = 0;\n"
        "uint64 init(){ testvalue = stm_now(); return testvalue; }\n"
           "uint64 fini(){ return testvalue; }\n"
         "uint64 step(){ return stm_laptime(testvalue); }\n"
        ,0,0
    );

    if(r == 0) {
        r = asModule_Build(_state.module);
         if(r == 0) {
            _state.call_init = asModule_GetFunctionByDecl(_state.module,"uint64 init()");
            _state.call_fini = asModule_GetFunctionByDecl(_state.module,"uint64 fini()");
            _state.call_step = asModule_GetFunctionByDecl(_state.module,"uint64 step()");
        }
    }

    sg_desc graphics_desc = { 0 };
    graphics_desc.context = sapp_sgcontext();
    sg_setup(&graphics_desc);

    stm_setup();

    if (_state.context && _state.call_step) {
        if (asContext_Prepare(_state.context,_state.call_init)>=0){
            asContext_Execute(_state.context);
            uint64_t test = asContext_GetReturnQWord(_state.context);
            asContext_Unprepare(_state.context);
            fprintf(stdout, "call init result %u\n", test);
        }
    }
}

static void 
main_frame(void) {

    if (_state.context && _state.call_step) {
        if (asContext_Prepare(_state.context, _state.call_step) >= 0) {
            asContext_Execute(_state.context);
            uint64_t test = asContext_GetReturnQWord(_state.context);
            fprintf(stdout, "call step result %u\n", test);
            asContext_Unprepare(_state.context);
        }
    }

    sg_pass_action pass_action = { 0 };
    sg_begin_default_pass(&pass_action, sapp_width(), sapp_height());

    sg_end_pass();
    sg_commit();
}

static void
main_cleanup(void) {

     if (_state.context && _state.call_fini) {
        if (asContext_Prepare(_state.context, _state.call_fini) >= 0) {
            asContext_Execute(_state.context);
            uint64_t test = asContext_GetReturnQWord(_state.context);
            fprintf(stdout, "call fini result %u\n", test);
            asContext_Unprepare(_state.context);
        }
    }

    if (_state.engine && _state.context)  asEngine_ReturnContext(_state.engine, _state.context);
    if (_state.engine) asEngine_ShutDownAndRelease(_state.engine);
    sg_shutdown();
}

static void 
main_event(const sapp_event* e) {

}

static sapp_desc
sokol_main(int argc, char* argv[]) {
    (void)argc;
    (void)argv;

    sapp_desc app_desc = { 0 };
    app_desc.init_cb = main_init;
    app_desc.frame_cb = main_frame;
    app_desc.cleanup_cb = main_cleanup;
    app_desc.event_cb = main_event;
    app_desc.width = 400;
    app_desc.height = 300;
    app_desc.window_title = "Sokol Angelscript";
    app_desc.win32_console_attach = true;
    app_desc.enable_clipboard = true;
    app_desc.enable_dragndrop = true;
    app_desc.icon.sokol_default = true;
    return app_desc;
}


