#pragma once

#include "DxLib.h"
#include "InputKey.h"
#include "InputPad.h"
#include "InputMouse.h"
#include "GameMain.h"
#include <math.h>
#include <string>
#include <array>
#include <vector>
#include <cassert>


#define PI		 (3.141592653589793f)
#define RadToDeg (57.29577951f)
#define R2D(rad) (rad * RadToDeg)

#define DegToRad (0.017453293f)
#define D2R(deg) (deg * DegToRad)

#define SIZE(vars) (sizeof(vars) / sizeof(vars[0]))

#define BLACK	GetColor(0, 0, 0)
#define WHITE	GetColor(255, 255, 255)
#define RED		GetColor(255, 0, 0)
#define GREEN	GetColor(0, 255, 0)
#define BLUE	GetColor(0, 0, 255)
#define YELLOW	GetColor(255, 255, 0)
#define PINK	GetColor(255, 0, 255)
#define SKYBLUE	GetColor(0, 255, 255)

#define WINDOW_W	960
#define WINDOW_H	540

#define IMG_SIZE	32

// =====================================================
//		ç\ë¢ëÃ
// =====================================================
// ç¿ïW
struct Pos
{
	float x = 0;
	float y = 0;
};

// =====================================================
//		óÒãìëÃ
// =====================================================
// å¸Ç´
enum DIR
{
	DOWN = 0,
	LEFT, RIGHT,
	UP,
};

// =====================================================
//		ä÷êî
// =====================================================
// 2ì_ä‘ÇÃãóó£ÇãÅÇﬂÇÈ
float getDist(const Pos& pos1, const Pos& pos2);
