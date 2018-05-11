# SolitaireAI
Command line solitaire controlled through string commands by either a human or AI player.

## Game Commands
**NEWGAME** - Starts a new game.  
**DRAW** - Draws three cards from the deck.  
**MOVE x y destination** - Moves the card (and all its children) from column x, row y to the destination column.  
**MOVE x destination** - Moves the card (and all its children) from column x to the destination column (assumes the row).  
**MOVE x** - Moves the card (and all its children) from column x to the first available column (assumes best move).  
