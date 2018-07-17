/*
In an exam room, there are N seats in a single row, numbered 0, 1, 2, ..., N-1.

When a student enters the room, they must sit in the seat that maximizes the distance to the closest person.  If there are multiple such seats, they sit in the seat with the lowest number.  (Also, if no one is in the room, then the student sits at seat number 0.)

Return a class ExamRoom(int N) that exposes two functions: ExamRoom.seat() returning an int representing what seat the student sat in, and ExamRoom.leave(int p) representing that the student in seat number p now leaves the room.  It is guaranteed that any calls to ExamRoom.leave(p) have a student sitting in seat p.

 

Example 1:

Input: ["ExamRoom","seat","seat","seat","seat","leave","seat"], [[10],[],[],[],[],[4],[]]
Output: [null,0,9,4,2,null,5]
Explanation:
ExamRoom(10) -> null
seat() -> 0, no one is in the room, then the student sits at seat number 0.
seat() -> 9, the student sits at the last seat number 9.
seat() -> 4, the student sits at the last seat number 4.
seat() -> 2, the student sits at the last seat number 2.
leave(4) -> null
seat() -> 5, the student​​​​​​​ sits at the last seat number 5.
​​​​​​​

Note:

1 <= N <= 10^9
ExamRoom.seat() and ExamRoom.leave() will be called at most 10^4 times across all test cases.
Calls to ExamRoom.leave(p) are guaranteed to have a student currently sitting in seat number p.
*/
// max_heap and set
class ExamRoom {
private:
    int n;
    set<int> seats; // store the seats student seated
    priority_queue<vector<int>> gap;//store the availble (distance, -location, start, end)
    void store(int start,int end){// save a (distance, -location, start, end) into pq
        if(end-start>1){
            if(start == -1)// bound condition 1
                gap.push({end-start-2, -start-1, start, end});
            else if(end == n)// bound condition 1
                gap.push({end-start-2, -end+1, start, end});
            else// normal condition
                gap.push({(end-start-2)/2, -start-(end-start)/2, start, end});
        }
    }
public:
    ExamRoom(int N) {
        n=N;
        seats.insert(-1);
        seats.insert(n);
        store(-1, n);
    }
    
    int seat() {
        int seat = 0, start=-1, end=n;
        // find the seat
        while(!gap.empty()){
            vector<int> s = gap.top();
            gap.pop();
            auto left = seats.find(s[2]), right = seats.find(s[3]);
            // an available seat should satisfy that the start position and the end position of that gap pair 
            // are the previous seat and the next seat
            if(left!=seats.end() && right!=seats.end() && distance(left, right) == 1){
                seat = -s[1];
                start = s[2];
                end = s[3];
                break;
            }
        }
        //insert new seat And store two new parts splited by this seat location.
        seats.insert(seat);
        store(start, seat);
        store(seat, end);
        return seat;
    }
    
    void leave(int p) {
        auto s = seats.find(p);// find that seat, 
        auto start = s, end = s;// the previous position of the seat and the next one.
        --start, ++end;
        
        store(*(start), *(end));// recover the splited parts 
        seats.erase(s);// delete such seat
    }
};

// sorted seats, find the max distance seat by seat.
class ExamRoom {
private:
    int n;
    vector<int> seats;
public:
    ExamRoom(int N) {
        n=N-1;
    }
    
    int seat() {
        int dis = 0, pos = 0;
        auto where = seats.begin();
        if(seats.size()>0) dis = seats.front();
        for(int i=1;i<seats.size();++i){
            if((seats[i]-seats[i-1])/2>dis){
                dis = (seats[i]-seats[i-1])/2;
                pos = seats[i-1]+dis;
                where = seats.begin()+i;
            }
        }
        if(seats.size()>0 && n-seats.back()>dis){
            pos = n;
            where = seats.end();
        }
        seats.insert(where, pos);
        return pos;
    }
    
    void leave(int p) {
        seats.erase(find(seats.begin(),seats.end(),p));
    }
};
/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom obj = new ExamRoom(N);
 * int param_1 = obj.seat();
 * obj.leave(p);
 */
/*

["ExamRoom","seat","seat","seat","seat"]
[[10],[],[],[],[]]
["ExamRoom","seat","seat","seat","seat","leave"]
[[10],[],[],[],[],[4]]
["ExamRoom","seat","seat","seat","seat","leave","seat"]
[[10],[],[],[],[],[4],[]]
["ExamRoom","seat","seat","seat","leave","leave","seat","seat","seat","seat","seat","seat","seat","seat","seat","leave","leave","seat","seat","leave","seat","leave","seat","leave","seat","leave","seat","leave","leave","seat","seat","leave","leave","seat","seat","leave"]
[[10],[],[],[],[0],[4],[],[],[],[],[],[],[],[],[],[0],[4],[],[],[7],[],[3],[],[3],[],[9],[],[0],[8],[],[],[0],[8],[],[],[2]]
*/