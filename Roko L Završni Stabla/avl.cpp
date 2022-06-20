#include "functions.hh"
int avlinsert(avlpointer operand, avlpointer home) { //home èvorovi, u koje ubacujemo operand
    switch (home->binarychecktype(operand)) {
    case 1:
        avlinsertint(operand, home);
        return 0;
        break;
    case 2:
        avlinsertstring(operand, home);
        return 0;
        break;
    default:
        return -1;
    }
}
avlpointer avlinsertint(avlpointer operand, avlpointer home) { //home èvorovi, u koje ubacujemo operand
    /*if (home == NULL) {
        return operand;
    }*/
    if (operand->numberkey < home->numberkey) {
        if (home->leftchild == NULL) {
            home->leftchild = operand;
        }
        else {
            home->leftchild = avlinsertint(operand, (avlpointer)home->leftchild);
        }
        home = balance(home);
    }
    else if (operand->numberkey > home->numberkey) {
        if (home->rightchild == NULL) {
            home->rightchild = operand;
        }
        else {
            home->rightchild = avlinsertint(operand, (avlpointer)home->rightchild);
        }
        home = balance(home);
    }
    else {
        free(operand);
    }
    return home;
}
avlpointer avlinsertstring(avlpointer operand, avlpointer home) { //home èvorovi, u koje ubacujemo operand
    if (home == NULL) {
        return operand;
    }
    if (operand->stringkey < home->stringkey) {
        home->leftchild = avlinsertstring(operand, (avlpointer)home->leftchild);
        home = balance(home);
    }
    else if (operand->stringkey > home->stringkey) {
        home->rightchild = avlinsertstring(operand, (avlpointer)home->rightchild);
        home = balance(home);
    }
    else {
        free(operand);
    }
    return home;
}
int avlnode::height() {
    int h = 0;
    int max_height = 0, l_height = 0, r_height =0;
    if (this != NULL) {
        if (this->leftchild != NULL) {
            l_height = this->leftchild->height();
        }
        else {
            l_height = 0;
        }
        if (this->rightchild != NULL) {
            r_height = this->rightchild->height();
        }
        else {
            r_height = 0;
        }
        if (l_height > r_height)
            max_height = l_height;
        else
            max_height = r_height;
        h = max_height + 1;
    }
    return h;
}

int avlnode::difference() {
    int l_height, r_height;
    if (this->leftchild != NULL) {
        l_height = this->leftchild->height();
    }
    else {
        l_height = 0;
    }

    if (this->rightchild != NULL) {
        r_height = this->rightchild->height();
    }
    else {
        r_height = 0;
    }
    int b_factor = l_height - r_height;
    return b_factor;
}

int avldelete(avlpointer home, int value, string word, int mode) { //destroy the node of that value and rearange other nodes
    if (mode == 1) {
        avldeleteint(home, value);
    }
    else {
        avldeletestring(home, word);
    }
    return 1;
} 
avlpointer avldeleteint(avlpointer home, int value) {
    if (home == NULL)
        return home;

    // If the key to be deleted is
    // smaller than the home's
    // key, then it lies in left subtree
    if (value < home->numberkey) {
        home->leftchild = avldeleteint((avlpointer)home->leftchild, value);
        home = balance(home);
    }


    // If the key to be deleted is
    // greater than the home's
    // key, then it lies in right subtree
    else if (value > home->numberkey) {
        home->rightchild = avldeleteint((avlpointer)home->rightchild, value);
        home = balance(home);
    }

    // if key is same as home's key, then home is the node
    // to be deleted
    else {
        // node has no child
        if (home->leftchild == NULL and home->rightchild == NULL) {
            free(home);
            return NULL;
        }
        // node with only one child or no child
        else if (home->leftchild == NULL) {
            avlpointer temp = (avlpointer)home->rightchild;
            free(home);
            return temp;
        }
        else if (home->rightchild == NULL) {
            avlpointer temp = (avlpointer)home->leftchild;
            free(home);
            return temp;
        }

        // node with two children: Get the inorder successor
        // (smallest in the right subtree)
        avlpointer temp = (avlpointer)minvaluenode(home->rightchild);

        // Copy the inorder successor's content to home node
        home->numberkey = temp->numberkey;

        // Delete the inorder successor

        avldeleteint((avlpointer)home->rightchild, temp->numberkey);

        //free(temp);
    }
    return home;
};
avlpointer avldeletestring(avlpointer home, string word) {
    if (home == NULL)
        return home;

    // If the key to be deleted is
    // smaller than the home's
    // key, then it lies in left subtree
    if (word < home->stringkey) {
        home->leftchild = home->leftchild->binarydeletestring(word);
        home = balance(home);
    }

    // If the key to be deleted is
    // greater than the home's
    // key, then it lies in right subtree
    else if (word > home->stringkey){
        home->rightchild = home->rightchild->binarydeletestring(word);
        home = balance(home);
    }

    // if key is same as home's key, then home is the node
    // to be deleted
    else {
        // node has no child
        if (home->leftchild == NULL and home->rightchild == NULL) {
            free(home);
            return NULL;
        }
        // node with only one child or no child
        else if (home->leftchild == NULL) {
            binarypointer temp = home->rightchild;
            free(home);
            return (avlpointer)temp;
        }
        else if (home->rightchild == NULL) {
            binarypointer temp = home->leftchild;
            free(home);
            return (avlpointer)temp;
        }

        // node with two children: Get the inorder successor
        // (smallest in the right subtree)
        binarypointer temp = minvaluenode(home->rightchild);

        // Copy the inorder successor's content to home node
        home->stringkey = temp->stringkey;

        // Delete the inorder successor

        home->rightchild->binarydeletestring(temp->stringkey);

        //free(temp);
    }
    return home;
};

avlpointer avlnode::rr_rotat() {
    avlpointer t;
    t = (avlpointer) this->rightchild;
    this->rightchild = t->leftchild;
    t->leftchild = this;
    cout << "Right-Right Rotation";
    return t;
}
avlpointer avlnode::ll_rotat() {
    avlpointer t;
    t = (avlpointer)this->leftchild;
    this->leftchild = t->rightchild;
    t->rightchild = this;
    cout << "Left-Left Rotation";
    return t;
}
avlpointer avlnode::lr_rotat() {
    avlpointer t;
    t = (avlpointer)this->leftchild;
    this->leftchild = t->rr_rotat();
    cout << "Left-Right Rotation";
    return this->ll_rotat();
}
avlpointer avlnode::rl_rotat() {
    avlpointer t;
    t = (avlpointer)this->rightchild;
    this->rightchild = t->ll_rotat();
    cout << "Right-Left Rotation";
    return this->rr_rotat();
}
 avlpointer balance(avlpointer t) {
    if (t == NULL)
        return NULL;
    int bal_factor = t->difference();
    if (bal_factor > 1) {
        if (t->leftchild->difference() > 0)
            t = t->ll_rotat();
        else
            t = t->lr_rotat();
    }
    else if (bal_factor < -1) {
        if (t->rightchild->difference() > 0)
            t = t->rl_rotat();
        else
            t = t->rr_rotat();
    }
    return t;
}
