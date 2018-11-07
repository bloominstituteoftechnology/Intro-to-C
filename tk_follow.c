    int x = 1, y = 2, z[10];
    int *ip;

    ip = &x;         // What is ip here?
    y = *ip;          // What is y here?
    *ip = 0;          // What is ip here now? What is x now?
    ip = &z[0];    // What is ip now?