	.file	"ex1.c"
# GNU C11 (GCC) version 5.3.0 (x86_64-unknown-linux-gnu)
#	compiled by GNU C version 5.3.0, GMP version 6.1.0, MPFR version 3.1.3-p5, MPC version 1.0.3
# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed:  ex1.c -mtune=generic -march=x86-64 -Wall -fverbose-asm
# options enabled:  -faggressive-loop-optimizations
# -fasynchronous-unwind-tables -fauto-inc-dec -fchkp-check-incomplete-type
# -fchkp-check-read -fchkp-check-write -fchkp-instrument-calls
# -fchkp-narrow-bounds -fchkp-optimize -fchkp-store-bounds
# -fchkp-use-static-bounds -fchkp-use-static-const-bounds
# -fchkp-use-wrappers -fcommon -fdelete-null-pointer-checks
# -fdwarf2-cfi-asm -fearly-inlining -feliminate-unused-debug-types
# -ffunction-cse -fgcse-lm -fgnu-runtime -fgnu-unique -fident
# -finline-atomics -fira-hoist-pressure -fira-share-save-slots
# -fira-share-spill-slots -fivopts -fkeep-static-consts
# -fleading-underscore -flifetime-dse -flto-odr-type-merging -fmath-errno
# -fmerge-debug-strings -fpeephole -fprefetch-loop-arrays
# -freg-struct-return -fsched-critical-path-heuristic
# -fsched-dep-count-heuristic -fsched-group-heuristic -fsched-interblock
# -fsched-last-insn-heuristic -fsched-rank-heuristic -fsched-spec
# -fsched-spec-insn-heuristic -fsched-stalled-insns-dep -fschedule-fusion
# -fsemantic-interposition -fshow-column -fsigned-zeros
# -fsplit-ivs-in-unroller -fstdarg-opt -fstrict-volatile-bitfields
# -fsync-libcalls -ftrapping-math -ftree-coalesce-vars -ftree-cselim
# -ftree-forwprop -ftree-loop-if-convert -ftree-loop-im -ftree-loop-ivcanon
# -ftree-loop-optimize -ftree-parallelize-loops= -ftree-phiprop
# -ftree-reassoc -ftree-scev-cprop -funit-at-a-time -funwind-tables
# -fverbose-asm -fzero-initialized-in-bss -m128bit-long-double -m64 -m80387
# -malign-stringops -mavx256-split-unaligned-load
# -mavx256-split-unaligned-store -mfancy-math-387 -mfp-ret-in-387 -mfxsr
# -mglibc -mieee-fp -mlong-double-80 -mmmx -mno-sse4 -mpush-args -mred-zone
# -msse -msse2 -mtls-direct-seg-refs -mvzeroupper

	.section	.rodata
.LC0:
	.string	"%c"
.LC1:
	.string	"P2"
.LC2:
	.string	"%d"
.LC3:
	.string	"%d\n"
.LC4:
	.string	"%d%d%d"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$32, %rsp	#,
	leaq	-21(%rbp), %rax	#, tmp102
	movq	%rax, %rsi	# tmp102,
	movl	$.LC0, %edi	#,
	movl	$0, %eax	#,
	call	__isoc99_scanf	#
	leaq	-21(%rbp), %rax	#, tmp103
	movq	%rax, %rsi	# tmp103,
	movl	$.LC0, %edi	#,
	movl	$0, %eax	#,
	call	__isoc99_scanf	#
	movl	$.LC1, %edi	#,
	call	puts	#
	leaq	-20(%rbp), %rax	#, tmp104
	movq	%rax, %rsi	# tmp104,
	movl	$.LC2, %edi	#,
	movl	$0, %eax	#,
	call	__isoc99_scanf	#
	movl	-20(%rbp), %eax	# max, D.2312
	movl	%eax, %esi	# D.2312,
	movl	$.LC3, %edi	#,
	movl	$0, %eax	#,
	call	printf	#
	leaq	-20(%rbp), %rax	#, tmp105
	movq	%rax, %rsi	# tmp105,
	movl	$.LC2, %edi	#,
	movl	$0, %eax	#,
	call	__isoc99_scanf	#
	movl	-20(%rbp), %eax	# max, D.2312
	movl	%eax, %esi	# D.2312,
	movl	$.LC3, %edi	#,
	movl	$0, %eax	#,
	call	printf	#
	leaq	-20(%rbp), %rax	#, tmp106
	movq	%rax, %rsi	# tmp106,
	movl	$.LC2, %edi	#,
	movl	$0, %eax	#,
	call	__isoc99_scanf	#
	movl	$255, %esi	#,
	movl	$.LC3, %edi	#,
	movl	$0, %eax	#,
	call	printf	#
	jmp	.L2	#
.L3:
	movl	-8(%rbp), %eax	# r, D.2312
	imull	$7650, %eax, %edx	#, D.2312, D.2312
	movl	-12(%rbp), %eax	# g, D.2312
	imull	$15045, %eax, %eax	#, D.2312, D.2312
	addl	%eax, %edx	# D.2312, D.2312
	movl	-16(%rbp), %eax	# b, D.2312
	imull	$2805, %eax, %eax	#, D.2312, D.2312
	addl	%edx, %eax	# D.2312, D.2312
	movl	-20(%rbp), %edx	# max, D.2312
	imull	$100, %edx, %ecx	#, D.2312, D.2312
	cltd
	idivl	%ecx	# D.2312
	movl	%eax, -4(%rbp)	# tmp107, gray
	movl	-4(%rbp), %eax	# gray, tmp109
	movl	%eax, %esi	# tmp109,
	movl	$.LC3, %edi	#,
	movl	$0, %eax	#,
	call	printf	#
.L2:
	leaq	-16(%rbp), %rcx	#, tmp110
	leaq	-12(%rbp), %rdx	#, tmp111
	leaq	-8(%rbp), %rax	#, tmp112
	movq	%rax, %rsi	# tmp112,
	movl	$.LC4, %edi	#,
	movl	$0, %eax	#,
	call	__isoc99_scanf	#
	cmpl	$3, %eax	#, D.2312
	je	.L3	#,
	movl	$1, %eax	#, D.2312
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 5.3.0"
	.section	.note.GNU-stack,"",@progbits
