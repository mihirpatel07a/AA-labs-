//line segment

#include <bits/stdc++.h>
using namespace std;

struct point{
    int x;
    int y;
};

int direction(point p1, point p2, point p3){
    int ax = p3.x - p1.x;
    int ay = p3.y - p1.y;
    
    int bx = p2.x - p1.x;
    int by = p2.y - p1.y;
    
    int ans = ax*by - ay*bx;
    return ans;
}

bool OnSegment(point p1, point p2, point p3){
    if((min(p1.x,p2.x) <= p3.x && p3.x <= max(p1.x, p2.x)) && (min(p1.y,p2.y) <= p3.y && p3.y <= max(p1.y, p2.y))){
        return true;
    }
    else{
        return false;
    }
}

bool segment_intersection(point p1, point p2, point p3, point p4){
    int d1 = direction(p3, p4, p1);
    int d2 = direction(p3, p4, p2);
    int d3 = direction(p1, p2, p3);
    int d4 = direction(p1, p2, p4);
    
    if(d1*d2 < 0 && d3*d4 < 0){
        return true;
    }
    else if(d1 == 0 && OnSegment(p3,p4,p1)){
        return true;
    }
    else if(d2 == 0 && OnSegment(p3,p4,p2)){
        return true;
    }
    else if(d3 == 0 && OnSegment(p1,p2,p3)){
        return true;
    }
    else if(d4 == 0 && OnSegment(p1,p2,p4)){
        return true;
    }
    else{
        return false;
    }
}

int main()
{
    struct point p[4];
    
    for(int i=0 ; i<4 ; i++){
        int tx, ty;
        cin >> tx >> ty;
        p[i].x = tx;
        p[i].y = ty;
    }
    
    if(segment_intersection(p[0], p[1], p[2], p[3]) == true){
        cout << "segment intersects";
    }
    else{
        cout << "segment not intersect";
    }
    
    return 0;
}
