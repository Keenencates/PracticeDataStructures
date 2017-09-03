class node(object):
    def __init__(self, data=None, nxt=None):
        self.data = data
        self.nxt = nxt

class linked_list(object):
    def __init__(self, head=None):
        if is instance(head, node):
            self.head = head
        else:
            raise(TypeError)

    def append(self, data):
        if is instance(data, node):
            self.head.next = data
        else:
            self.head.next = node(data)
    
    def 


