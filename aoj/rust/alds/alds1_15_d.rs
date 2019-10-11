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

use std::cmp::Ordering;
use std::collections::{BTreeMap, BinaryHeap};

enum HuffmanTree {
    Leaf(char, u32),
    Node(u32, Box<HuffmanTree>, Box<HuffmanTree>),
}

impl HuffmanTree {
    fn get_freq(&self) -> u32 {
        match self {
            Leaf(_, f) => *f,
            Node(f, _, _) => *f,
        }
    }

    fn add(o1: HuffmanTree, o2: HuffmanTree) -> HuffmanTree {
        let f1 = o1.get_freq();
        let f2 = o2.get_freq();
        Node(f1 + f2, Box::new(o1), Box::new(o2))
    }

    fn print(&self) {
        match self {
            Leaf(c, f) => {
                print!("('{}': {})", c, f);
            }
            Node(f, l, r) => {
                print!("({} ", f);
                l.print();
                print!(" ");
                r.print();
                print!(")");
            }
        }
    }

    fn count(&self, i: u32) -> u32 {
        match self {
            Leaf(_, f) => i * f,
            Node(_, l, r) => l.count(i + 1) + r.count(i + 1),
        }
    }
}

impl Eq for HuffmanTree {}

impl PartialEq for HuffmanTree {
    fn eq(&self, other: &Self) -> bool {
        self.get_freq() == other.get_freq()
    }
}

impl PartialOrd for HuffmanTree {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        other.get_freq().partial_cmp(&self.get_freq())
    }
}

impl Ord for HuffmanTree {
    fn cmp(&self, other: &Self) -> Ordering {
        other.get_freq().cmp(&self.get_freq())
    }
}

use HuffmanTree::{Leaf, Node};

fn main() {
    let s: String = read::read();
    let cv: Vec<char> = s.chars().collect();

    let mut map: BTreeMap<char, u32> = BTreeMap::new();

    for c in cv {
        match map.get(&c) {
            None => {
                map.insert(c, 1);
            }
            Some(i) => {
                map.insert(c, i + 1);
            }
        }
    }

    let mut heap: BinaryHeap<HuffmanTree> = BinaryHeap::new();

    for (k, v) in &map {
        heap.push(Leaf(*k, *v));
    }

    while heap.len() > 1 {
        let t1 = heap.pop().unwrap();
        let t2 = heap.pop().unwrap();
        heap.push(HuffmanTree::add(t1, t2));
    }

    let t = heap.pop().unwrap();

    if let Leaf(_, f) = t {
        println!("{}", f);
    } else {
        println!("{}", t.count(0));
    }
}
