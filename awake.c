#include <ApplicationServices/ApplicationServices.h>
#include <unistd.h>

int main() {
	// move to 200x00
	CGEventRef move1 = CGEventCreateMouseEvent(
			NULL, kCGEventMouseMoved,
			CGPointMake(78, 78),
			kCGMouseButtonLeft // ignored
			);
	// move to 250x250
	CGEventRef move2 = CGEventCreateMouseEvent(
			NULL, kCGEventMouseMoved,
			CGPointMake(250, 250),
			kCGMouseButtonLeft // ignored
			);
	// left button down at 250x250
	CGEventRef click1_down = CGEventCreateMouseEvent(
			NULL, kCGEventLeftMouseDown,
			CGPointMake(78, 78),
			kCGMouseButtonLeft
			);
	// left button up at 250x250
	CGEventRef click1_up = CGEventCreateMouseEvent(
			NULL, kCGEventLeftMouseUp,
			CGPointMake(78, 78),
			kCGMouseButtonLeft
			);


	while (1)
	{
		//execute with interval
		CGEventPost(kCGHIDEventTap, move1);
		sleep(83);
		CGEventPost(kCGHIDEventTap, click1_down);
		sleep(1);
		CGEventPost(kCGHIDEventTap, click1_up);
	}
		//release events
		CFRelease(click1_up);
		CFRelease(click1_down);
		CFRelease(move2);
		CFRelease(move1);
	

	return 0;
}
