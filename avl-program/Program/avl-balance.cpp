/* Goal: To balance an AVL tree */
template <typename T>
void AVL<T>::balance()
{
    if (empty())
        return;
    
    fix_height();
    int balance_factor = bfactor();

    if (balance_factor == 2)       // Right subtree is taller by 2
    {
        if (right_subtree().bfactor() < 0) // Case 4: insertion to the L of RT
            right_subtree().rotate_right();
        return rotate_left();      // Cases 1 or 4: Insertion to the R/L of RT
    }
    else if (balance_factor == -2) // Left subtree is taller by 2
    {
        if (left_subtree().bfactor() > 0) // Case 3: insertion to the R of LT
            left_subtree().rotate_left();
        return rotate_right();     // Cases 2 or 3: insertion to the L/R of LT
    }
    // Balancing is not required for the remaining cases
}
