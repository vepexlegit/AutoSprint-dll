#include "Cheat.h"
#include "Java.h"
#include <chrono>
#include <thread>
#include <Windows.h>

using namespace std;
using namespace chrono;
using namespace this_thread;

jclass getMinecraftClass() {
	return ct.env->FindClass("ave");
}

jobject getMinecraft() {
	jmethodID getMinecraftMethod = ct.env->GetStaticMethodID(getMinecraftClass(), "A", "()Lave;");
	return ct.env->CallStaticObjectMethod(getMinecraftClass(), getMinecraftMethod);
}

jobject getWorld() {
	jfieldID getWorldField = ct.env->GetFieldID(getMinecraftClass(), "f", "Lbdb;");
	return ct.env->GetObjectField(getMinecraft(), getWorldField);
}

jobject getPlayer() {
	jfieldID getPlayerField = ct.env->GetFieldID(getMinecraftClass(), "h", "Lbew;");
	return ct.env->GetObjectField(getMinecraft(), getPlayerField);
}

void setPlayerSprint() {
	if (!GetAsyncKeyState('W') || GetAsyncKeyState('S') || GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_LCONTROL)) return;
	jmethodID setSprintingMethod = ct.env->GetMethodID(ct.env->GetObjectClass(getPlayer()), "d", "(Z)V");
	ct.env->CallBooleanMethod(getPlayer(), setSprintingMethod, true);
}

void runModules() {
	while (true) {
		if (GetAsyncKeyState(VK_END)) break;

		if (!getMinecraft()) continue;
		if (!getPlayer()) continue;
		if (!getWorld()) continue;

		setPlayerSprint();

		sleep_for(milliseconds(5));
	}
}