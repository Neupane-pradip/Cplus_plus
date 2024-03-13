#include "cards.hh"

// Constructor for the Cards class, initializes
// the top_ pointer to nullptr
Cards::Cards() : top_(nullptr) {}

// Returns the topmost card in the stack
Card_data *Cards::get_topmost() {
    return top_;
}

// Adds a new card with the given id to the top of the stack
void Cards::add(int id) {
    Card_data *new_card = new Card_data;
    new_card->data = id;
    new_card->next = top_;
    top_ = new_card;
}

// Prints the cards from top to bottom, with each card's position and data
void Cards::print_from_top_to_bottom(std::ostream &s) {
    Card_data *current_card = top_;
    uint i = 1;
    while (current_card != nullptr) {
        s << i++ << ": " << current_card->data << "\n";
        current_card = current_card->next;
    }
}

// Removes the topmost card and returns its id.
// Returns false if the stack is empty
bool Cards::remove(int &id) {
    if (top_ == nullptr) {
        return false;
    }
    Card_data *temp = top_;
    top_ = top_->next;
    id = temp->data;
    delete temp;
    return true;
}

// Moves the bottom card to the top of the stack.
// Returns false if the stack has less than two cards
bool Cards::bottom_to_top() {
    if (top_ == nullptr || top_->next == nullptr) {
        return false;
    }

    Card_data *last = top_,
              *second = top_;
    while (last->next != nullptr) {
        second = last;
        last = last->next;
    }

    second->next = nullptr;
    last->next = top_;
    top_ = last;
    return true;
}

// Moves the top card to the bottom of the stack.
// Returns false if the stack has less than two cards
bool Cards::top_to_bottom() {
    if (top_ == nullptr || top_->next == nullptr) {
        return false;
    }

    Card_data *temp = top_,
              *last = top_;
    top_ = top_->next;

    while (last->next != nullptr) {
        last = last->next;
    }

    last->next = temp;
    temp->next = nullptr;
    return true;
}

// Prints the cards from bottom to top using a recursive function
void Cards::print_from_bottom_to_top(std::ostream &s) {
    recursive_print(top_, s);
}

// Destructor for the Cards class, deallocates memory
// for all cards in the stack
Cards::~Cards() {
    Card_data *temp = top_;
    while (top_ != nullptr) {
        top_ = top_->next;
        delete temp;
        temp = top_;
    }
}

// Recursive function to print cards from bottom to top
int Cards::recursive_print(Card_data *top, std::ostream &s) {
    int i = 1;
    if (top->next != nullptr) {
        i += recursive_print(top->next, s);
    }
    s << i << ": " << top->data << std::endl;
    return i;
}
