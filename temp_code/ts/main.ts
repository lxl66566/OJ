function permute<T>(arr: T[], callback: (arr: readonly T[]) => void) {
	const backtrack = (start: number) => {
		if (start === arr.length - 1) {
			callback(arr);
			return;
		}
		for (let i = start; i < arr.length; i++) {
			[arr[start], arr[i]] = [arr[i], arr[start]]; // Swap
			backtrack(start + 1);
			[arr[start], arr[i]] = [arr[i], arr[start]]; // Backtrack
		}
	};
	backtrack(0);
}
const arr = [1, 2, 3];
permute(arr, console.log);
