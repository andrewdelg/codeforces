#[allow(unused_imports)]
use std::cmp::{min,max};
use std::io::{BufWriter, stdin, stdout, Write};
use std::collections::{ HashSet, VecDeque};
 
#[derive(Default)]
struct Scanner {
    buffer: Vec<String>
}
impl Scanner {
    fn next<T: std::str::FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buffer.pop() {
                return token.parse().ok().expect("Failed parse");
            }
            let mut input = String::new();
            stdin().read_line(&mut input).expect("Failed read");
            self.buffer = input.split_whitespace().rev().map(String::from).collect();
        }
    }
}

fn in_bounds(i: i64, j: i64, n: i64, m: i64) -> bool {
  return 0 <= i && i < n && 0 <= j && j < m;
}
 
fn main() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());
    
    let n = scan.next::<usize>();
    let m = scan.next::<usize>();
    let k = scan.next::<usize>();

    let mut maze: Vec<Vec<char>> = Vec::new();
    let mut start: (i64, i64) = (0, 0);
    for i in 0..n {
      // strings are finky :/
      let mut tmp: Vec<char> = Vec::new();
      let line = scan.next::<String>();
      for (j, c) in line.as_str().chars().enumerate() {
        tmp.push(c);
        if c == '.' {
          start = (i as i64, j as i64)
        }
      }
      maze.push(tmp)
    }


    let mut visited: HashSet<(i64, i64)> = HashSet::new();
    let mut by_distance: Vec<(i64, i64)> = Vec::new();
    let mut deque: VecDeque<(i64, i64)> = VecDeque::new();

    deque.push_back(start);

    while !deque.is_empty() {
      //println!("{:?}", deque);
      let current = deque.pop_front().unwrap();
      if visited.contains(&current) {
        continue;
      }
      visited.insert(current);
      by_distance.push(current);

      let next = (current.0 - 1, current.1);
      if in_bounds(next.0, next.1, n as i64, m as i64) && !visited.contains(&next) && *maze.get(next.0 as usize).unwrap().get(next.1 as usize).unwrap() == '.' {
        deque.push_back(next.clone());
      }

      let next = (current.0 + 1, current.1);
      if in_bounds(next.0, next.1, n as i64, m as i64) && !visited.contains(&next) && *maze.get(next.0 as usize).unwrap().get(next.1 as usize).unwrap() == '.' {
        deque.push_back(next.clone());
      }

      let next = (current.0, current.1 - 1);
      if in_bounds(next.0, next.1, n as i64, m as i64) &&  !visited.contains(&next) && *maze.get(next.0 as usize).unwrap().get(next.1 as usize).unwrap() == '.' {
        deque.push_back(next.clone());
      }

      let next = (current.0, current.1 + 1);
      if in_bounds(next.0, next.1, n as i64, m as i64) && !visited.contains(&next) && *maze.get(next.0 as usize).unwrap().get(next.1 as usize).unwrap() == '.' {
        deque.push_back(next.clone());
      }
    }


    //println!("{:?}", by_distance);
    let mut new_walls = HashSet::new();

    for _ in 0..k {
      new_walls.insert(by_distance.pop().unwrap());
    }

    for i in 0..n {
      for j in 0..m {
        if new_walls.contains(&(i as i64, j as i64)) {
          write!(out, "X").ok();
        } else {
          write!(out, "{}", maze.get(i as usize).unwrap().get(j as usize).unwrap()).ok();
        }
      }
      writeln!(out, "").ok();
    }


}