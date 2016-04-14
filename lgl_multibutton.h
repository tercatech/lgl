#pragma once

#include "lgl_object.h"
#include "lgl_const.h"

typedef struct {
	int x1;
	int x2;
	int y1;
	int y2;
} multibutton_data;

class lgl_multibutton : public lgl_object {
public:
	lgl_multibutton(int corner_x, int corner_y, int extend, int era, int color, float scale) : lgl_object(era, color, scale){
		data.x1 = corner_x;
		data.x2 = corner_x + lgl_const::button_width;
		data.y1 = corner_y;
		data.y2 = corner_y + lgl_const::button_height;
		
		this->extend = extend; 
	}
	~lgl_multibutton(){}
	
	int setvalue(int value);
	
	virtual int draw();
protected:
	int value;
	multibutton_data data;
private:
	int extend;
};
