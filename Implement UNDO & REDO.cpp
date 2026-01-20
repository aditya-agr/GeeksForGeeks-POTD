class Solution {
  public:
    string doc;
    string redu;
    void append(char x) {
        // append x into document
        doc.push_back(x);
    }

    void undo() {
        // undo last change
        if(doc.length()){
            redu.push_back(doc.back());
            doc.pop_back();
        }
    }

    void redo() {
        // redo changes
        if(redu.length()){
            doc.push_back(redu.back());
            redu.pop_back();
        }
    }

    string read() {
        // read the document
        return doc;
    }
};