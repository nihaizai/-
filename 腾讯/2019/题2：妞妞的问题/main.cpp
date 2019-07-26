#include <iostream>
#include <algorithm>
using namespace std;

//根据两个坐标形成的矩形，计算矩形内黑色方块个数b和白色方块个数w.
void getWhiteAndBlack(const int x0,const int y0,const int x1,const int y1,int& w,int& b){
	
	int count = (x1 - x0 + 1) * (y1 - y0 + 1);
	//起始节点坐标和为奇数，则起始方块颜色为黑色
	if ((x0 + y0) & 1) {
		//方块总个数为奇数，则起始方块颜色多一个
		if (count & 1){
			w = count / 2;
			b = count - w;
		}
		else{
			w = b = count / 2;
		}
	}
	//起始坐标和为偶数，则起始方块为白色
	else{
		if (count & 1){
			b = count / 2;
			w = count - b;
		}
		else{
			w = b = count / 2;
		}
	}
}

void WhiteAndBlack(){
	int T;
	cin >> T;
	while (T--){
		int n, m;
		cin >> n >> m;
		int x0, y0, x1, y1;
		int x2, y2, x3, y3;
		cin >> x0 >> y0 >> x1 >> y1;
		cin >> x2 >> y2 >> x3 >> y3;

		
		int black = n*m / 2;
		int white = n*m - black;

		int b1 = 0;
		int w1 = 0;
		getWhiteAndBlack(x0, y0, x1, y1, w1, b1);
		//cout << w1 <<"   "<<b1 << endl;

		int w2 = 0;
		int b2 = 0;
		getWhiteAndBlack(x2, y2, x3, y3, w2, b2);
		//cout << w2 << "   "<<b2<<endl;


		int maskX0 = max(x0, x2);
		int maskY0 = max(y0, y2);
		int maskX1 = min(x1, x3);
		int maskY1 = min(y1,y3);

		int maskB = 0;
		int maskW = 0;
		if (maskX1 >= maskX0 && maskY1 >= maskY0){
			getWhiteAndBlack(maskX0,maskY0,maskX1,maskY1,maskW,maskB);
			//cout << maskW << "   " << maskB << endl;
		}
		//第一轮将形成的矩形内全部涂白，因此白色方块个数加上其中的黑色方块个数b1，
		//黑色方块个数减去其个数b1；
		//第二轮将形成的矩形内全部涂黑，因此黑色方块个数加上其中的白色方块个数w2，
		//白色方块个数减去其个数w2；
		//两轮重合的区域矩形中，由于第二轮是按照未进行第一轮涂白操作进行的计算，因此
		//黑色方块个数少计算了第一轮涂白的方块个数也就是最初的黑色方块个数maskB，
		//白色方块个数多计算了maskB.
		white = white + b1 - w2 - maskB;
		black = black - b1 + w2 + maskB;
		cout << white << " " << black << endl;

	}

}


int main(){
	WhiteAndBlack();
	return 0;
}


参考链接：
https://blog.csdn.net/lx8486/article/details/92974201
