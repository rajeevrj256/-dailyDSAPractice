class BrowserHistory {
public:
    stack<string>backwardst;
    stack<string>forwardSt;
    string homepagestr;
    BrowserHistory(string homepage) {
        homepagestr=homepage;
        backwardst.push(homepage);
    }
    
    void visit(string url) {
        backwardst.push(url);

        while(!forwardSt.empty()){
              forwardSt.pop();
        }
    }
    
    string back(int steps) {
        while(backwardst.size()>1 && steps){
           string topel= backwardst.top();
            backwardst.pop();
            
            forwardSt.push(topel);steps--;
        }

        return backwardst.top();
    }
    
    string forward(int steps) {

       string topel;
         while(!forwardSt.empty() && steps){
            topel= forwardSt.top();
            forwardSt.pop();

            backwardst.push(topel);steps--;
        }

        return backwardst.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forwardSt(steps);
 */