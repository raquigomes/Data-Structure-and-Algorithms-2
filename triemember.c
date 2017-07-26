int TrieIsMember(trieADT trie, char keys[])
{
  /* Start at the top level. */
  trieNodeT *level = trie->root;

  /* Start at beginning of key. */
  int i = 0;

  for (;;) {
    trieNodeT *found = NULL;
    trieNodeT *curr;

    for (curr = level; curr != NULL; curr = curr->next) {
      /*
       * Want a node at this level to match
       * the current character in the key.
       */
      if (curr->key == keys[i]) {
        found = curr;
        break;
      }
    }

    /*
     * If either no nodes at this level or none
     * with next character in key, then key not
     * present.
     */
    if (found == NULL)
      return 0;

    /* If we matched end of key, it's there! */
    if (keys[i] == '\0')
      return 1;

    /* Go to next level. */
    level = found->children;

    /* Advance in string key. */
    i++;
  }
}
