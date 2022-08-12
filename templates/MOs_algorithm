// MO's Algorithm
class compare{
public:
	bool operator()(query &a, query &b){
		int l = a.l / BLK;
		int r = b.l / BLK;
		if(l == r){
			return a.r <= b.r;
		}else{
			return l <= r;
		}
	}	
};