/*
CLASS PHYSICS:
MAKE SOMETHING

*/

float nol(float a){
	if(a > 0)
		return 1;
	else if(a == 0)
		return 0;
	else
		return -1;
}


float isConstain(Vector2f p1, Vector2f p2, Vector2f point){
	return (p1.y-p2.y)*point.x + (p2.x-p1.x)*point.y + (p1.x*p2.y - p2.x*p1.y);
}

bool inShape(ConvexShape shape, Vector2f point){
	int n = shape.getPointCount();
	for(int i = 0; i < n; i++){
		if(
			nol(
				isConstain(
					shape.getPoint(i) + shape.getPosition(),
					shape.getPoint((i + 1) % n) + shape.getPosition(),
					point
				)
			)
			!=
			nol(
				isConstain(
					shape.getPoint(i) + shape.getPosition(),
					shape.getPoint((i + 1) % n) + shape.getPosition(),
					shape.getPoint((i + 2) % n) + shape.getPosition()
				)
			)
		){
			return false;
		}
	}
	return true;
}
