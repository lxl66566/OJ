use std::borrow::BorrowMut;
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

    fn get_mut(&self, index: i32) -> Rc<RefCell<Node<i32>>> {
        let mut node = self.head.clone();
        for _ in 0..index {
            node = node.clone().borrow().next.clone().unwrap();
        }
        node
    }

    fn get(&self, index: i32) -> i32 {
        self.get_mut(index).borrow().val
    }

    fn add_at_head(&mut self, val: i32) {
        let mut node = Node::new(val);
        node.next = Some(self.head.borrow().next.clone().unwrap());
        node.prev = Some(self.head.borrow().next.clone().unwrap());
        let some_rc_node = Some(Rc::new(RefCell::new(node)));
        if let Some(next) = self.head.borrow().next.as_deref() {
            next.borrow_mut().prev.clone_from(&some_rc_node);
        }
        self.head.borrow().next.borrow_mut() = some_rc_node;
        self.size += 1;
    }

    fn add_at_tail(&mut self, val: i32) {
        let mut node = Node::new(val);
        node.next.clone_from(&self.tail.borrow().next);
        node.prev.clone_from(&self.tail.borrow().prev);
        let rc_node = Rc::new(RefCell::new(node));
        let prev_tail = self
            .tail
            .borrow()
            .prev
            .clone()
            .unwrap_or_else(|| self.head.clone());
        prev_tail
            .clone()
            .borrow_mut()
            .next
            .borrow_mut()
            .clone_from(&Some(rc_node.clone()));
        self.tail = rc_node;
        self.size += 1;
    }

    fn add_at_index(&mut self, index: i32, val: i32) {
        let node = self.get_mut(index);
        let mut new_node = Node::new(val);
        new_node.prev = Some(node.clone());
        new_node.next = node.borrow().next.clone();
        let rc_new_node = Rc::new(RefCell::new(new_node));
        if let Some(next) = node.borrow().next.clone() {
            next.borrow_mut().prev = Some(rc_new_node.clone());
        }
        node.borrow_mut().next = Some(rc_new_node);
        self.size += 1;
    }

    // fn delete_at_index(&self, index: i32) {

    // }
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
        while let Some(next) = node.clone().borrow().next.clone() {
            node = next.clone();
            write!(f, "{} ", next.borrow().val)?;
        }
        write!(f, "]")?;
        Ok(())
    }
}

fn main() {
    let mut l = MyLinkedList::from_iter([1, 2, 3, 4]);
    l.add_at_index(2, 6);
    println!("{:#?}", l);
}
