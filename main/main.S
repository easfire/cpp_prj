
main.out:     file format elf64-x86-64


Disassembly of section .init:

0000000000400430 <_init>:
  400430:	f3 0f 1e fa          	endbr64 
  400434:	48 83 ec 08          	sub    $0x8,%rsp
  400438:	48 8b 05 b9 0b 20 00 	mov    0x200bb9(%rip),%rax        # 600ff8 <__gmon_start__>
  40043f:	48 85 c0             	test   %rax,%rax
  400442:	74 02                	je     400446 <_init+0x16>
  400444:	ff d0                	callq  *%rax
  400446:	48 83 c4 08          	add    $0x8,%rsp
  40044a:	c3                   	retq   

Disassembly of section .plt:

0000000000400450 <.plt>:
  400450:	ff 35 b2 0b 20 00    	pushq  0x200bb2(%rip)        # 601008 <_GLOBAL_OFFSET_TABLE_+0x8>
  400456:	ff 25 b4 0b 20 00    	jmpq   *0x200bb4(%rip)        # 601010 <_GLOBAL_OFFSET_TABLE_+0x10>
  40045c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000400460 <printf@plt>:
  400460:	ff 25 b2 0b 20 00    	jmpq   *0x200bb2(%rip)        # 601018 <printf@GLIBC_2.2.5>
  400466:	68 00 00 00 00       	pushq  $0x0
  40046b:	e9 e0 ff ff ff       	jmpq   400450 <.plt>

0000000000400470 <puts@plt>:
  400470:	ff 25 aa 0b 20 00    	jmpq   *0x200baa(%rip)        # 601020 <puts@GLIBC_2.2.5>
  400476:	68 01 00 00 00       	pushq  $0x1
  40047b:	e9 d0 ff ff ff       	jmpq   400450 <.plt>

Disassembly of section .text:

0000000000400480 <_start>:
  400480:	f3 0f 1e fa          	endbr64 
  400484:	31 ed                	xor    %ebp,%ebp
  400486:	49 89 d1             	mov    %rdx,%r9
  400489:	5e                   	pop    %rsi
  40048a:	48 89 e2             	mov    %rsp,%rdx
  40048d:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
  400491:	50                   	push   %rax
  400492:	54                   	push   %rsp
  400493:	49 c7 c0 60 06 40 00 	mov    $0x400660,%r8
  40049a:	48 c7 c1 f0 05 40 00 	mov    $0x4005f0,%rcx
  4004a1:	48 c7 c7 62 05 40 00 	mov    $0x400562,%rdi
  4004a8:	ff 15 42 0b 20 00    	callq  *0x200b42(%rip)        # 600ff0 <__libc_start_main@GLIBC_2.2.5>
  4004ae:	f4                   	hlt    

00000000004004af <.annobin_init.c>:
  4004af:	90                   	nop

00000000004004b0 <_dl_relocate_static_pie>:
  4004b0:	f3 0f 1e fa          	endbr64 
  4004b4:	c3                   	retq   

00000000004004b5 <.annobin__dl_relocate_static_pie.end>:
  4004b5:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  4004bc:	00 00 00 
  4004bf:	90                   	nop

00000000004004c0 <deregister_tm_clones>:
  4004c0:	b8 40 10 60 00       	mov    $0x601040,%eax
  4004c5:	48 3d 40 10 60 00    	cmp    $0x601040,%rax
  4004cb:	74 13                	je     4004e0 <deregister_tm_clones+0x20>
  4004cd:	b8 00 00 00 00       	mov    $0x0,%eax
  4004d2:	48 85 c0             	test   %rax,%rax
  4004d5:	74 09                	je     4004e0 <deregister_tm_clones+0x20>
  4004d7:	bf 40 10 60 00       	mov    $0x601040,%edi
  4004dc:	ff e0                	jmpq   *%rax
  4004de:	66 90                	xchg   %ax,%ax
  4004e0:	c3                   	retq   
  4004e1:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
  4004e8:	00 00 00 00 
  4004ec:	0f 1f 40 00          	nopl   0x0(%rax)

00000000004004f0 <register_tm_clones>:
  4004f0:	be 40 10 60 00       	mov    $0x601040,%esi
  4004f5:	48 81 ee 40 10 60 00 	sub    $0x601040,%rsi
  4004fc:	48 89 f0             	mov    %rsi,%rax
  4004ff:	48 c1 ee 3f          	shr    $0x3f,%rsi
  400503:	48 c1 f8 03          	sar    $0x3,%rax
  400507:	48 01 c6             	add    %rax,%rsi
  40050a:	48 d1 fe             	sar    %rsi
  40050d:	74 11                	je     400520 <register_tm_clones+0x30>
  40050f:	b8 00 00 00 00       	mov    $0x0,%eax
  400514:	48 85 c0             	test   %rax,%rax
  400517:	74 07                	je     400520 <register_tm_clones+0x30>
  400519:	bf 40 10 60 00       	mov    $0x601040,%edi
  40051e:	ff e0                	jmpq   *%rax
  400520:	c3                   	retq   
  400521:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
  400528:	00 00 00 00 
  40052c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000400530 <__do_global_dtors_aux>:
  400530:	80 3d 05 0b 20 00 00 	cmpb   $0x0,0x200b05(%rip)        # 60103c <_edata>
  400537:	75 17                	jne    400550 <__do_global_dtors_aux+0x20>
  400539:	55                   	push   %rbp
  40053a:	48 89 e5             	mov    %rsp,%rbp
  40053d:	e8 7e ff ff ff       	callq  4004c0 <deregister_tm_clones>
  400542:	c6 05 f3 0a 20 00 01 	movb   $0x1,0x200af3(%rip)        # 60103c <_edata>
  400549:	5d                   	pop    %rbp
  40054a:	c3                   	retq   
  40054b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
  400550:	c3                   	retq   
  400551:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
  400558:	00 00 00 00 
  40055c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000400560 <frame_dummy>:
  400560:	eb 8e                	jmp    4004f0 <register_tm_clones>

0000000000400562 <main>:
  400562:	55                   	push   %rbp
  400563:	48 89 e5             	mov    %rsp,%rbp
  400566:	48 83 ec 10          	sub    $0x10,%rsp
  40056a:	89 7d fc             	mov    %edi,-0x4(%rbp)
  40056d:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  400571:	e8 11 00 00 00       	callq  400587 <_Z1fv>
  400576:	e8 0c 00 00 00       	callq  400587 <_Z1fv>
  40057b:	e8 07 00 00 00       	callq  400587 <_Z1fv>
  400580:	b8 00 00 00 00       	mov    $0x0,%eax
  400585:	c9                   	leaveq 
  400586:	c3                   	retq   

0000000000400587 <_Z1fv>:
  400587:	55                   	push   %rbp
  400588:	48 89 e5             	mov    %rsp,%rbp
  40058b:	8b 05 a7 0a 20 00    	mov    0x200aa7(%rip),%eax        # 601038 <_ZZ1fvE3all>
  400591:	89 c2                	mov    %eax,%edx
  400593:	be 7c 06 40 00       	mov    $0x40067c,%esi
  400598:	bf 7e 06 40 00       	mov    $0x40067e,%edi
  40059d:	b8 00 00 00 00       	mov    $0x0,%eax
  4005a2:	e8 b9 fe ff ff       	callq  400460 <printf@plt>
  4005a7:	8b 05 8b 0a 20 00    	mov    0x200a8b(%rip),%eax        # 601038 <_ZZ1fvE3all>
  4005ad:	83 c0 02             	add    $0x2,%eax
  4005b0:	89 05 82 0a 20 00    	mov    %eax,0x200a82(%rip)        # 601038 <_ZZ1fvE3all>
  4005b6:	8b 05 7c 0a 20 00    	mov    0x200a7c(%rip),%eax        # 601038 <_ZZ1fvE3all>
  4005bc:	89 c2                	mov    %eax,%edx
  4005be:	be 7c 06 40 00       	mov    $0x40067c,%esi
  4005c3:	bf 7e 06 40 00       	mov    $0x40067e,%edi
  4005c8:	b8 00 00 00 00       	mov    $0x0,%eax
  4005cd:	e8 8e fe ff ff       	callq  400460 <printf@plt>
  4005d2:	bf 8f 06 40 00       	mov    $0x40068f,%edi
  4005d7:	e8 94 fe ff ff       	callq  400470 <puts@plt>
  4005dc:	8b 05 56 0a 20 00    	mov    0x200a56(%rip),%eax        # 601038 <_ZZ1fvE3all>
  4005e2:	5d                   	pop    %rbp
  4005e3:	c3                   	retq   
  4005e4:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  4005eb:	00 00 00 
  4005ee:	66 90                	xchg   %ax,%ax

00000000004005f0 <__libc_csu_init>:
  4005f0:	f3 0f 1e fa          	endbr64 
  4005f4:	41 57                	push   %r15
  4005f6:	49 89 d7             	mov    %rdx,%r15
  4005f9:	41 56                	push   %r14
  4005fb:	49 89 f6             	mov    %rsi,%r14
  4005fe:	41 55                	push   %r13
  400600:	41 89 fd             	mov    %edi,%r13d
  400603:	41 54                	push   %r12
  400605:	4c 8d 25 c4 07 20 00 	lea    0x2007c4(%rip),%r12        # 600dd0 <__frame_dummy_init_array_entry>
  40060c:	55                   	push   %rbp
  40060d:	48 8d 2d c4 07 20 00 	lea    0x2007c4(%rip),%rbp        # 600dd8 <__init_array_end>
  400614:	53                   	push   %rbx
  400615:	4c 29 e5             	sub    %r12,%rbp
  400618:	48 83 ec 08          	sub    $0x8,%rsp
  40061c:	e8 0f fe ff ff       	callq  400430 <_init>
  400621:	48 c1 fd 03          	sar    $0x3,%rbp
  400625:	74 1f                	je     400646 <__libc_csu_init+0x56>
  400627:	31 db                	xor    %ebx,%ebx
  400629:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
  400630:	4c 89 fa             	mov    %r15,%rdx
  400633:	4c 89 f6             	mov    %r14,%rsi
  400636:	44 89 ef             	mov    %r13d,%edi
  400639:	41 ff 14 dc          	callq  *(%r12,%rbx,8)
  40063d:	48 83 c3 01          	add    $0x1,%rbx
  400641:	48 39 dd             	cmp    %rbx,%rbp
  400644:	75 ea                	jne    400630 <__libc_csu_init+0x40>
  400646:	48 83 c4 08          	add    $0x8,%rsp
  40064a:	5b                   	pop    %rbx
  40064b:	5d                   	pop    %rbp
  40064c:	41 5c                	pop    %r12
  40064e:	41 5d                	pop    %r13
  400650:	41 5e                	pop    %r14
  400652:	41 5f                	pop    %r15
  400654:	c3                   	retq   

0000000000400655 <.annobin___libc_csu_fini.start>:
  400655:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
  40065c:	00 00 00 00 

0000000000400660 <__libc_csu_fini>:
  400660:	f3 0f 1e fa          	endbr64 
  400664:	c3                   	retq   

Disassembly of section .fini:

0000000000400668 <_fini>:
  400668:	f3 0f 1e fa          	endbr64 
  40066c:	48 83 ec 08          	sub    $0x8,%rsp
  400670:	48 83 c4 08          	add    $0x8,%rsp
  400674:	c3                   	retq   
