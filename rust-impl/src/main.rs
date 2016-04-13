 // This program is free software; you can redistribute it and/or
 // modify it under the terms of the GNU Lesser General Public
 // License as published by the Free Software Foundation; either
 // version 2 of the License, or (at your option) any later version.

 // This library is distributed in the hope that it will be useful,
 // but WITHOUT ANY WARRANTY; without even the implied warranty of
 // MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 // Lesser General Public License for more details.

 // You should have received a copy of the GNU Lesser General Public
 // License along with this program. If not, see <http://www.gnu.org/licenses/>.

mod elf;
extern crate getopts;
use getopts::Options;

use std::{env, fs, process};
use std::io::{self, Write};
use std::fmt::Display;
use std::os::unix::fs::MetadataExt;

fn print_usage(program: &str, opts: Options) {
    let brief = format!("USAGE: {} <FILE> [OPTIONS]", program);

    print!("{}", opts.usage(&brief));
}

#[inline]
fn exit_err<T: Display>(msg: T, code: i32) -> ! {
    writeln!(&mut io::stderr(), "Error: {}", msg).expect("Could not write to stdout");
    process::exit(code)
}

fn parse_file(input: &str) {
    let metadata = fs::metadata(input).unwrap_or_else(|e| exit_err(e, 2));

    println!("`size of {} is {}.", input, metadata.size());

    println!("=== ELF info for `{}` ===\n", input);
    elf::elf_init();
}

fn main() {
    let args: Vec<String> = env::args().collect();
    let program = args[0].clone();

    let mut opts = Options::new();
    opts.optflag("h", "help", "print this help menu");
    let matches = match opts.parse(&args[1..]) {
        Ok(m) => {m}
        Err(f) => { panic!(f.to_string()) }
    };

    if matches.opt_present("h") {
        print_usage(&program, opts);
        return;
    }

    let input = if !matches.free.is_empty() {
        matches.free[0].clone()
    } else {
        print_usage(&program, opts);
        return;
    };

    parse_file(&input);

}
