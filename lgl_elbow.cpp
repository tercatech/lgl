#include "lgl_elbow.h"

#include <GL/gl.h>
#include <GL/glut.h>

#include "lgl_utils.h"
#include "lgl_shapes.h"
#include "lgl_const.h"

using namespace std;

int lgl_elbow::draw(){
	lgl_utils::colors(era, color);
	
	if(elbow.x_orient == 0){
		if(elbow.y_orient == 0) draw_x0_y0();
		else draw_x0_y1();
	}
	else{
		if(elbow.y_orient == 0) draw_x1_y0();
		else draw_x1_y1();
	}
}

int lgl_elbow::draw_x0_y0(){
	lgl_shapes::rectangle(elbow.x, elbow.x+lgl_const::button_width, elbow.y, elbow.y+10+elbow.size*lgl_const::button_height+(elbow.size-1)*2);
	lgl_shapes::arc(elbow.x+45, elbow.y+10+elbow.size*lgl_const::button_height+(elbow.size-1)*2, 45, 90, 180);
	lgl_shapes::rectangle(elbow.x+45, elbow.x+lgl_const::button_width+27, elbow.y+10+elbow.size*lgl_const::button_height+(elbow.size-1)*2, elbow.y+45+10+elbow.size*lgl_const::button_height+(elbow.size-1)*2);
	lgl_shapes::rectangle(elbow.x+lgl_const::button_width+27, elbow.x+lgl_const::button_width+elbow.length+27, elbow.y+27+10+elbow.size*lgl_const::button_height+(elbow.size-1)*2, elbow.y+45+10+elbow.size*lgl_const::button_height+(elbow.size-1)*2);
	
	glColor3f(0.0, 0.0, 0.0);
	
	lgl_shapes::arc(elbow.x+lgl_const::button_width+27, elbow.y+10+elbow.size*lgl_const::button_height+(elbow.size-1)*2, 27, 90, 180);
	lgl_utils::draw_text(elbow.x+5, elbow.y+5, 3, scale, text);
}

int lgl_elbow::draw_x1_y0(){
	lgl_shapes::rectangle(elbow.x+elbow.length+27, elbow.x+elbow.length+27+lgl_const::button_width, elbow.y, elbow.y+10+elbow.size*lgl_const::button_height+(elbow.size-1)*2);
	lgl_shapes::arc(elbow.x+elbow.length+27+(lgl_const::button_width-45), elbow.y+10+elbow.size*lgl_const::button_height+(elbow.size-1)*2, 45, 0, 90);
	lgl_shapes::rectangle(elbow.x+elbow.length, elbow.x+elbow.length+27+(lgl_const::button_width-45), elbow.y+10+elbow.size*lgl_const::button_height+(elbow.size-1)*2, elbow.y+45+10+elbow.size*lgl_const::button_height+(elbow.size-1)*2);
	lgl_shapes::rectangle(elbow.x, elbow.x+elbow.length, elbow.y+27+10+elbow.size*lgl_const::button_height+(elbow.size-1)*2, elbow.y+45+10+elbow.size*lgl_const::button_height+(elbow.size-1)*2);
	
	glColor3f(0.0, 0.0, 0.0);
	
	lgl_shapes::arc(elbow.x+elbow.length, elbow.y+10+elbow.size*lgl_const::button_height+(elbow.size-1)*2, 27, 0, 90);
	lgl_utils::draw_text(elbow.x+elbow.length+27+5, elbow.y+5, 3, scale, text);
}

int lgl_elbow::draw_x0_y1(){
	lgl_shapes::rectangle(elbow.x, elbow.x+lgl_const::button_width, elbow.y+45, elbow.y+45+10+elbow.size*lgl_const::button_height+(elbow.size-1)*2);
	lgl_shapes::arc(elbow.x+45, elbow.y+45, 45, 180, 270);
	lgl_shapes::rectangle(elbow.x+45, elbow.x+lgl_const::button_width+27, elbow.y, elbow.y+45);
	lgl_shapes::rectangle(elbow.x+lgl_const::button_width+27, elbow.x+lgl_const::button_width+elbow.length+27, elbow.y, elbow.y+18);
	
	glColor3f(0.0, 0.0, 0.0);
	
	lgl_shapes::arc(elbow.x+lgl_const::button_width+27, elbow.y+45, 27, 180, 270);
	lgl_utils::draw_text(elbow.x+5, elbow.y+45+lgl_const::button_height*elbow.size-15, 3, scale, text);
}

int lgl_elbow::draw_x1_y1(){
	lgl_shapes::rectangle(elbow.x+elbow.length+27, elbow.x+elbow.length+27+lgl_const::button_width, elbow.y+45, elbow.y+45+10+elbow.size*lgl_const::button_height+(elbow.size-1)*2);
	lgl_shapes::arc(elbow.x+elbow.length+27+(lgl_const::button_width-45), elbow.y+45, 45, -90, 0);
	lgl_shapes::rectangle(elbow.x+elbow.length, elbow.x+elbow.length+27+(lgl_const::button_width-45), elbow.y, elbow.y+45);
	lgl_shapes::rectangle(elbow.x, elbow.x+elbow.length, elbow.y, elbow.y+18);
	
	glColor3f(0.0, 0.0, 0.0);
	
	lgl_shapes::arc(elbow.x+elbow.length, elbow.y+45, 27, -90, 0);
	lgl_utils::draw_text(elbow.x+elbow.length+27+5, elbow.y+lgl_const::button_height*elbow.size+45-15, 3, scale, text);
}
