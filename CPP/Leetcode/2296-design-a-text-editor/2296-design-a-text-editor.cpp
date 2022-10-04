class TextEditor {
private:
    list<char>a;
    // If delete, will delete position cur - 1, not position cur.
    list<char>::iterator cur;
public:
    TextEditor() {
        a.clear();
        // For convenience.
        a.push_back('A');
        cur = a.end();
    }
    
    void addText(string text) {
        a.insert(cur, text.begin(), text.end());
    }
    
    int deleteText(int k) {
        int cnt = 0;
        // Move to the position that will be deleted.
        cur--;
        while(k--){
            if(cur==a.begin())break;
            cnt++;
            a.erase(cur--);
        }
        // Adjust the position of the cursor.
        cur++;
        return cnt;
    }
    
    // Left 10 chars.
    string solve() {
        auto tt = cur;
        tt--;
        string ret;
        int k = 10;
        while(k--){
            if(tt==a.begin())break;
            ret += (*(tt--));
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
    
    string cursorLeft(int k) {
        while(k--){
            auto nxt = cur;
            nxt--;
            // Never move the cursor to the first position.
            if(nxt==a.begin())break;
            cur = nxt;
        }
        return solve();
    }
    
    string cursorRight(int k) {
        while(k--){
            if(cur==a.end())break;
            cur++;
        }
        return solve();
    }
};