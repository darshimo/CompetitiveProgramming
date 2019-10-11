pub fn read<T: std::str::FromStr>() -> T {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).ok();
    s.trim().parse().ok().unwrap()
}

pub fn read_vec<T: std::str::FromStr>() -> Vec<T> {
    read::<String>()
        .split_whitespace()
        .map(|e| e.parse().ok().unwrap())
        .collect()
}

pub fn read_vec2<T: std::str::FromStr>(n: u32) -> Vec<Vec<T>> {
    (0..n).map(|_| read_vec()).collect()
}

pub fn read_col<T: std::str::FromStr>(n: u32) -> Vec<T> {
    (0..n).map(|_| read()).collect()
}

use std::clone::Clone;

enum BTree {
    Empty,
    Node(i32, Box<BTree>, Box<BTree>),
}

use BTree::{Empty, Node};

impl Clone for BTree {
    fn clone(&self) -> BTree {
        match self {
            Empty => Empty,
            Node(x, l, r) => Node(x.clone(), l.clone(), r.clone()),
        }
    }
}

impl BTree {
    fn print_inorder(&self) {
        match self {
            Empty => {}
            Node(x, l, r) => {
                l.print_inorder();
                print!(" {}", x);
                r.print_inorder();
            }
        }
    }

    fn print_preorder(&self) {
        match self {
            Empty => {}
            Node(x, l, r) => {
                print!(" {}", x);
                l.print_preorder();
                r.print_preorder();
            }
        }
    }

    fn insert(&self, i: i32) -> BTree {
        match self {
            Empty => Node(i, Box::new(Empty), Box::new(Empty)),
            Node(x, l, r) => {
                if i < *x {
                    Node(*x, Box::new(l.insert(i)), r.clone())
                } else if *x < i {
                    Node(*x, l.clone(), Box::new(r.insert(i)))
                } else {
                    Node(*x, l.clone(), r.clone())
                }
            }
        }
    }

    fn find(&self, i: i32) -> bool {
        match self {
            Empty => false,
            Node(x, l, r) => {
                if i < *x {
                    l.find(i)
                } else if *x < i {
                    r.find(i)
                } else {
                    true
                }
            }
        }
    }

    fn min(&self) -> i32 {
        match self {
            Empty => panic!("cannot find minimum element in empty tree."),
            Node(x, l, r) => {
                if l.is_empty() {
                    *x
                } else {
                    l.min()
                }
            }
        }
    }

    fn delete_min(&self) -> BTree {
        match self {
            Empty => panic!("cannot delete minimum element in empty tree."),
            Node(x, l, r) => {
                if l.is_empty() {
                    *r.clone()
                } else {
                    Node(*x, Box::new(l.delete_min()), r.clone())
                }
            }
        }
    }

    fn is_empty(&self) -> bool {
        match self {
            Empty => true,
            _ => false,
        }
    }

    fn delete(&self, i: i32) -> BTree {
        match self {
            Empty => Empty,
            Node(x, l, r) => {
                if i < *x {
                    Node(*x, Box::new(l.delete(i)), r.clone())
                } else if *x < i {
                    Node(*x, l.clone(), Box::new(r.delete(i)))
                } else if l.is_empty() {
                    *r.clone()
                } else if r.is_empty() {
                    *l.clone()
                } else {
                    Node(r.min(), l.clone(), Box::new(r.delete_min()))
                }
            }
        }
    }
}

fn main() {
    let m: u32 = read();
    let commands: Vec<String> = read_col(m);

    let mut tree = Empty;

    for cmd in commands {
        if cmd == "print" {
            tree.print_inorder();
            println!("");
            tree.print_preorder();
            println!("");
        } else {
            let c: Vec<String> = cmd
                .split_whitespace()
                .map(|e| e.parse().ok().unwrap())
                .collect();
            let x: i32 = c[1].parse().ok().unwrap();
            if c[0] == "insert" {
                tree = tree.insert(x);
            } else if c[0] == "find" {
                if tree.find(x) {
                    println!("yes");
                } else {
                    println!("no");
                }
            } else {
                tree = tree.delete(x);
            }
        }
    }
}
