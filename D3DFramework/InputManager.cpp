#include "InputManager.h"

void InputManager::SetMousePosition(D3DXVECTOR2 pos)
{
	CurMousePos = pos;
}

//마우스 움직임 포착
void InputManager::InputUpdate()
{
	MouseAxis.x = CurMousePos.x - PreMousePos.x;
	MouseAxis.y = CurMousePos.y - PreMousePos.y;

	if (keybuf['W'])
	{
		if (VerticalAxis < 1)
		{
			VerAxisVal += AxisAccel;
			VerticalAxis += VerAxisVal;
			if (VerticalAxis > 1)
			{
				VerticalAxis = 1;
				VerAxisVal = 0;
			}
		}
		
	}
	else if (keybuf['S'])
	{
		if (VerticalAxis > -1)
		{
			VerAxisVal -= AxisAccel;
			VerticalAxis += VerAxisVal;
			if (VerticalAxis < -1)
			{
				VerticalAxis = -1;
				VerAxisVal = 0;
			}
		}
	}
	

	if (keybuf['D'])
	{
		if (HorizentalAxis < 1)
		{
			HorAxisVal += AxisAccel;
			HorizentalAxis += HorAxisVal;
			if (HorizentalAxis > 1)
			{
				HorizentalAxis = 1;
				HorAxisVal = 0;
			}
		}
	}
	else if(keybuf['A'])
	{
		if (HorizentalAxis > -1)
		{
			HorAxisVal -= AxisAccel;
			HorizentalAxis += HorAxisVal;
			if (HorizentalAxis < -1)
			{
				HorizentalAxis = -1;
				HorAxisVal = 0;
			}
		}
	}
	
	if (!keybuf['W'] && !keybuf['S'])
	{
		if (VerticalAxis != 0.0f)
		{
			if (VerticalAxis >= 0)
			{
				VerAxisVal -= AxisAccel;
				VerticalAxis += VerAxisVal;
				if (VerticalAxis <= 0)
				{
					VerticalAxis = 0;
					VerAxisVal = 0;
				}
			}
			else
			{
				VerAxisVal += AxisAccel;
				VerticalAxis += VerAxisVal;
				if (VerticalAxis >= 0)
				{
					VerticalAxis = 0;
					VerAxisVal = 0;
				}
			}

			/*if (fabs(VerticalAxis) <= 0.01f)
			{
				VerAxisVal = 0;
				VerticalAxis = 0;
			}*/
		}
		
	}

	if (!keybuf['D'] && !keybuf['A'])
	{
		if (HorizentalAxis != 0.0f)
		{
			if (HorizentalAxis >= 0)
			{
				HorAxisVal -= AxisAccel;
				HorizentalAxis += HorAxisVal;
				if (HorizentalAxis <= 0)
				{
					HorizentalAxis = 0;
					HorAxisVal = 0;
				}
			}
			else
			{
				HorAxisVal += AxisAccel;
				HorizentalAxis += HorAxisVal;
				if (HorizentalAxis >= 0)
				{
					HorizentalAxis = 0;
					HorAxisVal = 0;
				}
			}

		
		}
		
	}
}

void InputManager::KeyDown(char input)
{
	keybuf[input] = true;
}

void InputManager::KeyUp(char input)
{
	keybuf[input] = false;
	/*if (!keybuf['W'])
	{
		VerticalAxis = 0;
		VerAxisVal = 0;
	}
	if (!keybuf['S'])
	{
		VerticalAxis = 0;
		VerAxisVal = 0;
	}
	if (!keybuf['D'])
	{
		HorizentalAxis = 0;
		HorAxisVal = 0;
	}
	if (!keybuf['A'])
	{
		HorizentalAxis = 0;
		HorAxisVal = 0;
	}*/
}

bool InputManager::GetKey(char code)
{
	return keybuf[code];
}

D3DXVECTOR2 InputManager::GetMouseAxis()
{
	return MouseAxis;
}
void InputManager::MouseButtonDown(char input)
{
	mousebuf[input] = true;
}
void InputManager::MouseButtonUp(char input)
{
	mousebuf[input] = false;
}

bool InputManager::GetMouseButton(char code)
{
	return mousebuf[code];
}