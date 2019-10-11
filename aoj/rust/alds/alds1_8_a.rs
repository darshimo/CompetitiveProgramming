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
            tree = tree.insert(x);
        }
    }
}
