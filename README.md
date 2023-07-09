# coff programming language

see parser.y for technical syntax details

## base program structure
```
prog program_id {

    con const_id   = value;
        const_2_id = value2;

    var var_id  : type;
        var_2_id: type;

    subprog:
        func func_id(foo: type; bar: type): type {
            ret foo / bar;
        }

    main {
        var_id := func_id(value*value2, value2);
    }

}
```