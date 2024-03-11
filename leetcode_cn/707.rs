use std::cell::RefCell;
use std::fmt;
use std::rc::Rc;

#[derive(Default)]
struct Node<T> {
    val: T,
    next: Option<Rc<RefCell<Node<T>>>>,
    prev: Option<Rc<RefCell<Node<T>>>>,
}
impl<T> Node<T>
where
    T: Default,
{
    pub fn new(v: T) -> Self {
        Self {
            val: v,
            ..Default::default()
        }
    }
}
struct MyLinkedList {
    head: Rc<RefCell<Node<i32>>>,
    tail: Rc<RefCell<Node<i32>>>,
    size: usize,
}
impl MyLinkedList {
    fn new() -> Self {
        let head = Rc::new(RefCell::new(Node::default()));
        MyLinkedList {
            tail: head.clone(),
            head,
            size: 0,
        }
    }

    // index = 0: first
    // index = -1: head
    fn get_mut(&self, index: i32) -> Rc<RefCell<Node<i32>>> {
        let mut node = self.head.clone();
        for _ in -1..index {
            let next = node.borrow().next.clone().unwrap();
            node = next;
        }
        node
    }

    fn get(&self, index: i32) -> i32 {
        dbg!(self.size);
        if index < 0 || index >= self.size as i32 {
            return -1;
        }
        self.get_mut(index).borrow().val
    }

    fn add_at_head(&mut self, val: i32) {
        self.add_at_index(0, val)
    }

    fn add_at_tail(&mut self, val: i32) {
        self.add_at_index(self.size as i32, val);
    }

    fn add_at_index(&mut self, index: i32, val: i32) {
        if index < 0 || index > self.size as i32 {
            return;
        }
        // this function add num behind the index.
        let index = index - 1;
        let insert_behind = self.get_mut(index);
        let insert_before = insert_behind.borrow().next.clone();
        let mut new_node = Node::new(val);
        new_node.prev = Some(insert_behind.clone());
        new_node.next = insert_before.clone();
        let option_new_node = Some(Rc::new(RefCell::new(new_node)));
        if let Some(next) = insert_before {
            next.borrow_mut().prev = option_new_node.clone();
        }
        insert_behind.borrow_mut().next = option_new_node;
        self.size += 1;
    }

    fn delete_at_index(&mut self, index: i32) {
        if index < 0 || index >= self.size as i32 || self.size == 0 {
            return;
        }
        let del = self.get_mut(index);
        let prev = del.borrow().prev.clone();
        let next = del.borrow().next.clone();
        prev.clone().unwrap().borrow_mut().next = next.clone();
        if let Some(next_some) = next {
            next_some.borrow_mut().prev = prev;
        }
        self.size -= 1;
    }
}

impl FromIterator<i32> for MyLinkedList {
    fn from_iter<T: IntoIterator<Item = i32>>(iter: T) -> Self {
        let mut l = Self::new();
        for i in iter.into_iter() {
            l.add_at_tail(i);
        }
        l
    }
}

impl fmt::Debug for MyLinkedList {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "[ ")?;
        let mut node = self.head.clone();
        let mut times = 0;
        while let Some(next) = node.clone().borrow().next.clone() {
            write!(f, "{} ", next.borrow().val)?;
            node = next;
            times += 1;
            if times >= self.size {
                break;
            }
        }
        write!(f, "]")?;
        Ok(())
    }
}

fn main() {
    let mut l = MyLinkedList::new();
    // l.add_at_head(1);
    // l.delete_at_index(0);
    l.add_at_head(1);
    l.add_at_tail(3);
    l.add_at_index(1, 2);
    println!("{:#?}", l);
}
