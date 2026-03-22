bool has_cycle(int winner, int loser)
{
    // Base case: if the loser is already a winner over our current winner
    if (winner == loser)
    {
        return true;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        // If the loser beats 'i', check if 'i' eventually beats the winner
        if (locked[loser][i])
        {
            if (has_cycle(winner, i))
            {
                return true;
            }
        }
    }
    return false;
}
