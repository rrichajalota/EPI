/* Intersection of Rectangles
** WAP which tests if two rectangles have a non-empty intersection. If they intersect, return the rectangle formed by their intersection.
** Given : the lowermost point of the rectangle (x,y),
** 		   width of the rectangle, and 
** 		   height of the rectangle. 
*/ 

#include <iostream>
using namespace std;

struct Rectangle{
int x; int y; int width; int height;
};

Rectangle computeCommonRectangle(struct Rectangle, struct Rectangle);
bool isIntersect(struct Rectangle, struct Rectangle);

int main() {
	// your code goes here
	Rectangle r1, r2;
	r1.x= 1, r1.y=2, r1.width=3, r1.height=5;
	r2.x= 3, r2.y=4, r2.width=2, r2.height=3;
	Rectangle r3= computeCommonRectangle(r1,r2);
	cout<<r3.x<<" "<<r3.y<<" "<<r3.width<<" "<<r3.height<<endl;
	return 0;
}

Rectangle computeCommonRectangle(struct Rectangle r1, struct Rectangle r2){
	Rectangle r3;
	if (isIntersect(r1,r2)){
		r3.x= max(r1.x,r2.x);
		r3.y= max(r1.y,r2.y),
		r3.width= min(r1.x+r1.width, r2.x+r2.width)-max(r1.x,r2.x);
		r3.height= min(r1.y+r1.height,r2.y + r2.height)-max(r1.y,r2.y);
	}
	else{
		r3.x= 0;
		r3.y= 0;
		r3.width= -1;
		r3.height= -1;
	}
	return r3;
}

bool isIntersect(struct Rectangle r1, struct Rectangle r2){
	return (r1.x <= r2.x+r2.width && 
			r1.x+r1.width >=r2.x && 
			r1.y <= r2.y+r2.height &&
			r1.y+ r1.height >= r2.y);
 }