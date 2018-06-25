; ModuleID = 'test.p'
source_filename = "test.p"
target datalayout = "e-m:e-p:64:64-i64:64-i128:128-n64-S128"

@aaaa = dso_local global float 0x40289999a0000000, align 4
@fff = dso_local global float zeroinitializer, align 4
@str = dso_local global [256 x i8] zeroinitializer, align 4
@ss = dso_local global [256 x i8] c"123\n\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00", align 4

declare dso_local void @print_real(float)
declare dso_local void @print_int(i32 signext)
declare dso_local void @print_bool(i32 signext)
declare dso_local void @print_text(i8*)

define dso_local signext i32 @main(i32 signext, i8**) {
	%aaaa = alloca i32, align 4
	store i32 -123, i32* %aaaa, align 4
	%fff = alloca float, align 4

	%.1 = alloca i32, align 4
	store i32 123, i32* %.1, align 4
%.2 = load i32, i32* %.1, align 4	call void @print_int(i32 signext %.2)
	%.3 = alloca float, align 4
	store float 0x40289999a0000000, float* %.3, align 4
%.4 = load float, float* %.3, align 4	call void @print_real(float %.4)
	%.5 = alloca i32, align 4
	store i32 1, i32* %.5, align 4
%.6 = load i32, i32* %.5, align 4	call void @print_bool(i32 signext %.6)
	ret i32 0
}

