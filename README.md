# 42_ft_containers
Reimplement C++ containers!
[IN PROGRESS]


to do list:
- vector : 
   - should _container be a ** instead of *, with additional alloc per element ??
   - test it as a ft::Vector<char *> and see if it breaks

-ALL: add max tests, 10000 elems for example

- map: order elements as a binary search list ordered depending on Compare()
   EXAMPLE key d
            /    \
            a     r
          /  \   / \
              b f   
               \
                c

- Redo a close reading of all mans to check if my implementations match
- Redo iterators because mine are incomplete and I didnt get any of this "tags" or "traits" business, so help me dog
- Use allocator ? Maybe not necessary

/!\ CHECK LEAKS FROM THE MAIN OFTEN, fsanitize doesn't seem to mind obvious leaks