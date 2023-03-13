fn main()
{
    let mut a = vec![1,2,3,4,5,6,7,8,9,10];
    a.iter_mut().enumerate().for_each(|(i,x)| {
        *x += i;
        println!("{} ",x);
    });
}