
bool check(Node topLeftA, Node topLeftB, Node bottomRightA, Node bottomRightB)
{
	if (bottomRightA.x <= topLeftB.x || bottomRightB.x <= topLeftA.x) return false;
	if (topLeftA.y <= bottomRightB.y || topLeftB.y <= bottomRightA.y) return false;
	return true;
}

bool check(Node topLeftA, Node topLeftB, Node bottomRightA, Node bottomRightB) {
	if (bottomRightA.x <= topLeftB.x || bottomRightB.x <= topLeftA.x) return false;
	if (topLeftA.y <= bottomRightB.y || topLeftB.y <= bottomRightA.y) return false;
	return true;
}