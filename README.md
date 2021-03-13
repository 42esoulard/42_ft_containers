# 42_ft_containers
Reimplement C++ containers!

to do list:
- vector : 
    node.setEnd() : go from begin, increment size times, and point end there
    node.getNext() / getPrev() : test increment/decrement
    vector.assign and all size modifiers : add a capacity check. if newSize > capacity, then capacity *= 2 and allocate newCapacity size vector.