// Your task is to maintain a data structure that supports the following functions of a web browser.

// 1- Browser(homepage): Set homepage of the browser

// 2- Visit(url): Visit the url from the current page. It clears up all the forward history.

// 3- Back(steps): Move ‘steps’ backward in the browser history

// 4- Forward(steps): Move ‘steps’ forward in the browser history

class Node{
    public:
    string data;
    Node *next;
    Node *back;
    Node() : data(""), next(nullptr), back(nullptr){};
    Node(string x) : data(x), next(nullptr), back(nullptr){};
    Node(string x, Node *next, Node *random) : data(x), next(next), back(random){};
};

class Browser
{
    public:
      Node* currentpage;
    Browser(string &homepage)
    {
         currentpage = new Node(homepage);
    }

    void visit(string &url)
    {
          Node* newNode = new Node(url);
        currentpage->next = newNode;
        newNode->back = currentpage;
        currentpage = newNode;
    }

    string back(int steps)
    {
        while(steps){
            if(currentpage->back)
            currentpage = currentpage->back;
            else
            break;
            steps--;
        }
        return currentpage->data;
    }

    string forward(int steps)
    {
        while(steps){
            if(currentpage->next)
            currentpage = currentpage->next;
            else
            break;
            steps--;
        }
        return currentpage->data;
    }
};
