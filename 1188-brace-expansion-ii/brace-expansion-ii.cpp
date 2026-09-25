class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        int index = 0;
        set<string> resultSet = parse(expression, index);
        return vector<string>(resultSet.begin(), resultSet.end());
    }

private:
    set<string> parse(const string& expr, int& i) {
        set<string> res;
        set<string> cur{""}; // Holds the strings built so far in the current block
        
        while (i < expr.size() && expr[i] != '}') {
            if (expr[i] == '{') {
                i++; // Skip '{'
                set<string> next = parse(expr, i); // Recursively parse the inner expression
                i++; // Skip '}'
                cur = computeProduct(cur, next);
            } else if (expr[i] == ',') {
                // Comma means we take the union, so push cur to res and reset cur
                res.insert(cur.begin(), cur.end());
                cur = {""}; 
                i++; // Skip ','
            } else {
                // Single letter: wrap it in a set and multiply into cur
                set<string> next{string(1, expr[i])};
                i++;
                cur = computeProduct(cur, next);
            }
        }
        
        // Add the last evaluated cur block into res before returning
        res.insert(cur.begin(), cur.end());
        return res;
    }

    // Helper to compute the Cartesian product (concatenation) of two sets
    set<string> computeProduct(const set<string>& a, const set<string>& b) {
        set<string> res;
        for (const string& x : a) {
            for (const string& y : b) {
                res.insert(x + y);
            }
        }
        return res;
    }
};