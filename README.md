# Wayland Client Testcase
- requirement is Qt 5.9 due to usage of QtWaylandCompositor

## Test Setup
- run compositor:
  export XDG_RUNTIME_DIR=/var/run
  /usr/bin/compositor -platform eglfs
- run client:
  export XDG_RUNTIME_DIR=/var/run
  /usr/bin/client -platform wayland

## Trigger the Crash
- touch on the red window creates another green window
- touch an a green window destroys the latest green windw

For performing the crash, just click on the red window, then the green (if it did not crash yet, repeat this).
After a couple of attempts, I get the crash.

## Used Hardware
 
# cat /proc/cpuinfo 
processor       : 0
model name      : ARMv7 Processor rev 10 (v7l)
BogoMIPS        : 3.00
Features        : half thumb fastmult vfp edsp neon vfpv3 tls vfpd32 
CPU implementer : 0x41
CPU architecture: 7
CPU variant     : 0x2
CPU part        : 0xc09
CPU revision    : 10

processor       : 1
model name      : ARMv7 Processor rev 10 (v7l)
BogoMIPS        : 3.00
Features        : half thumb fastmult vfp edsp neon vfpv3 tls vfpd32 
CPU implementer : 0x41
CPU architecture: 7
CPU variant     : 0x2
CPU part        : 0xc09
CPU revision    : 10

processor       : 2
model name      : ARMv7 Processor rev 10 (v7l)
BogoMIPS        : 3.00
Features        : half thumb fastmult vfp edsp neon vfpv3 tls vfpd32 
CPU implementer : 0x41
CPU architecture: 7
CPU variant     : 0x2
CPU part        : 0xc09
CPU revision    : 10

processor       : 3
model name      : ARMv7 Processor rev 10 (v7l)
BogoMIPS        : 3.00
Features        : half thumb fastmult vfp edsp neon vfpv3 tls vfpd32 
CPU implementer : 0x41
CPU architecture: 7
CPU variant     : 0x2
CPU part        : 0xc09
CPU revision    : 10

Hardware        : Freescale i.MX6 Quad/DualLite (Device Tree)
Revision        : 63015
Serial          : 0000000000000000


## Backtrace

Thread 6 (Thread 19007.19014):
#0  0x75ade7a4 in __pthread_cond_wait (cond=0x2dd418, mutex=<optimized out>) at /usr/src/debug/glibc/2.24-r0/git/nptl/pthread_cond_wait.c:186
        _a1 = 3003420
        _nr = 240
        _a3tmp = 15
        _a1tmp = 3003420
        _a3 = 15
        _a4tmp = 0
        _a2 = 128
        _a4 = 0
        __ret = <optimized out>
        futex_val = 15
        buffer = {__routine = 0x75ade4f4 <__condvar_cleanup>, __arg = 0x66bfed20, __canceltype = 0, __prev = 0x0}
        cbuffer = {oldtype = 0, cond = 0x2dd418, mutex = 0x2dd400, bc_seq = 0}
        err = <optimized out>
        pshared = 0
        val = <optimized out>
        seq = <optimized out>
#1  0x76044600 in QWaitConditionPrivate::wait (time=4294967295, this=0x2dd400) at /usr/src/debug/qtbase/5.9.2+gitAUTOINC+ec16ba393b-r0/git/src/corelib/thread/qwaitcondition_unix.cpp:143
        code = <optimized out>
#2  QWaitCondition::wait (this=this@entry=0x3c1160, mutex=0x77359400, mutex@entry=0x3c115c, time=time@entry=4294967295) at /usr/src/debug/qtbase/5.9.2+gitAUTOINC+ec16ba393b-r0/git/src/corelib/thread/qwaitcondition_unix.cpp:215
No locals.
#3  0x76dcdb0c in QSGRenderThreadEventQueue::takeEvent (wait=true, this=0x3c1158) at /usr/src/debug/qtdeclarative/5.9.2+gitAUTOINC+32218c3243-r0/git/src/quick/scenegraph/qsgthreadedrenderloop.cpp:245
No locals.
#4  QSGRenderThread::processEventsAndWaitForMore (this=this@entry=0x3c1108) at /usr/src/debug/qtdeclarative/5.9.2+gitAUTOINC+32218c3243-r0/git/src/quick/scenegraph/qsgthreadedrenderloop.cpp:709
No locals.
#5  0x76dce510 in QSGRenderThread::run (this=0x3c1108) at /usr/src/debug/qtdeclarative/5.9.2+gitAUTOINC+32218c3243-r0/git/src/quick/scenegraph/qsgthreadedrenderloop.cpp:738
No locals.
#6  0x76043488 in QThreadPrivate::start (arg=0x3c1108) at /usr/src/debug/qtbase/5.9.2+gitAUTOINC+ec16ba393b-r0/git/src/corelib/thread/qthread_unix.cpp:368
        __clframe = {__cancel_routine = 0x760425e0 <QThreadPrivate::finish(void*)>, __cancel_arg = 0x3c1108, __do_it = 1, __cancel_type = <optimized out>}
        thr = 0x3c1108
        data = 0x601fd0
#7  0x75ad7f5c in start_thread (arg=0x66bff450) at /usr/src/debug/glibc/2.24-r0/git/nptl/pthread_create.c:335
        pd = 0x66bff450
        unwind_buf = {cancel_jmp_buf = {{jmp_buf = {-731430043, -948579823, 1723855952, 2130704612, 0, 338, 0, 1723855952, 2130704612, 1723854732, 0 <repeats 54 times>}, mask_was_saved = 0}}, priv = {pad = {0x0, 0x0, 0x0, 0x0}, data = {prev = 0x0, cleanup = 0x0, canceltype = 0}}}
        not_first_call = <optimized out>
        robust = <optimized out>
        pagesize_m1 = <optimized out>
        sp = <optimized out>
        freesize = <optimized out>
        __PRETTY_FUNCTION__ = "start_thread"
#8  0x75dcd408 in ?? () at ../sysdeps/unix/sysv/linux/arm/clone.S:86 from /opt/sdk/cebis/sysroots/cortexa9hf-neon-mel-linux-gnueabi/lib/libc.so.6
No locals.
Backtrace stopped: previous frame identical to this frame (corrupt stack?)

Thread 5 (Thread 19007.19013):
#0  0x75dc4a40 in __GI_ppoll (fds=fds@entry=0x67800e68, nfds=nfds@entry=1, timeout=<optimized out>, timeout@entry=0x0, sigmask=sigmask@entry=0x0) at /usr/src/debug/glibc/2.24-r0/git/sysdeps/unix/sysv/linux/ppoll.c:39
        _a2tmp = 1
        _a2 = 1
        _a3 = 0
        _a1 = 1736445544
        _nr = 336
        _v1tmp = 8
        _a4tmp = 0
        _a1tmp = 1736445544
        _a4 = 0
        _v1 = 8
        _sys_result = <optimized out>
        sc_cancel_oldtype = 0
        sc_ret = <optimized out>
        tval = {tv_sec = 1, tv_nsec = 0}
#1  0x7627a458 in qt_ppoll (timeout_ts=0x0, nfds=1, fds=0x67800e68) at /usr/src/debug/qtbase/5.9.2+gitAUTOINC+ec16ba393b-r0/git/src/corelib/kernel/qcore_unix.cpp:81
No locals.
#2  qt_safe_poll (fds=0x67800e68, nfds=1, timeout_ts=0x0, timeout_ts@entry=0x7627bb5c <QEventDispatcherUNIX::processEvents(QFlags<QEventLoop::ProcessEventsFlag>)+480>) at /usr/src/debug/qtbase/5.9.2+gitAUTOINC+ec16ba393b-r0/git/src/corelib/kernel/qcore_unix.cpp:102
        ret = <optimized out>
        start = {tv_sec = 1736516212, tv_nsec = 1982320812}
        timeout = {tv_sec = 8526, tv_nsec = 137656681}
#3  0x7627bb5c in QEventDispatcherUNIX::processEvents (this=<optimized out>, flags=...) at /usr/src/debug/qtbase/5.9.2+gitAUTOINC+ec16ba393b-r0/git/src/corelib/kernel/qeventdispatcher_unix.cpp:500
        d = 0x67812218
        include_timers = <optimized out>
        include_notifiers = <optimized out>
        wait_for_events = <optimized out>
        canWait = <optimized out>
        tm = <optimized out>
        wait_tm = {tv_sec = 0, tv_nsec = 0}
        nevents = 0
#4  0x762203f8 in QEventLoop::exec (this=this@entry=0x68194e00, flags=..., flags@entry=...) at /usr/src/debug/qtbase/5.9.2+gitAUTOINC+ec16ba393b-r0/git/src/corelib/kernel/qeventloop.cpp:212
        d = 0x67813280
        locker = {val = 6299336}
        ref = {d = 0x67813280, locker = @0x68194db4, exceptionCaught = true}
#5  0x7603e820 in QThread::exec (this=this@entry=0x304580) at /usr/src/debug/qtbase/5.9.2+gitAUTOINC+ec16ba393b-r0/git/src/corelib/thread/qthread.cpp:515
        d = 0x601e88
        locker = {val = 6299336}
        eventLoop = {<QObject> = {_vptr.QObject = 0x7647b610 <vtable for QEventLoop+8>, static staticMetaObject = {d = {superdata = 0x0, stringdata = 0x763c8558 <qt_meta_stringdata_QObject>, data = 0x763c86d0 <qt_meta_data_QObject>, static_metacall = 0x76259c08 <QObject::qt_static_metacall(QObject*, QMetaObject::Call, int, void**)>, relatedMetaObjects = 0x0, extradata = 0x0}}, d_ptr = {d = 0x67813280}, static staticQtMetaObject = {d = {superdata = 0x0, stringdata = 0x763cb344 <qt_meta_stringdata_Qt>, data = 0x763c87e8 <qt_meta_data_Qt>, static_metacall = 0x0, relatedMetaObjects = 0x0, extradata = 0x0}}}, static staticMetaObject = {d = {superdata = 0x22c00 <QObject::staticMetaObject@@Qt_5>, stringdata = 0x763c52d8 <qt_meta_stringdata_QEventLoop>, data = 0x763c5330 <qt_meta_data_QEventLoop>, static_metacall = 0x762200d8 <QEventLoop::qt_static_metacall(QObject*, QMetaObject::Call, int, void**)>, relatedMetaObjects = 0x0, extradata = 0x0}}}
        returnCode = <optimized out>
#6  0x7673c518 in QQmlThreadPrivate::run (this=0x304580) at /usr/src/debug/qtdeclarative/5.9.2+gitAUTOINC+32218c3243-r0/git/src/qml/qml/ftw/qqmlthread.cpp:147
No locals.
#7  0x76043488 in QThreadPrivate::start (arg=0x304580) at /usr/src/debug/qtbase/5.9.2+gitAUTOINC+ec16ba393b-r0/git/src/corelib/thread/qthread_unix.cpp:368
        __clframe = {__cancel_routine = 0x760425e0 <QThreadPrivate::finish(void*)>, __cancel_arg = 0x304580, __do_it = 1, __cancel_type = <optimized out>}
        thr = 0x304580
        data = 0x305000
#8  0x75ad7f5c in start_thread (arg=0x68195450) at /usr/src/debug/glibc/2.24-r0/git/nptl/pthread_create.c:335
        pd = 0x68195450
        unwind_buf = {cancel_jmp_buf = {{jmp_buf = {-624827547, -948579823, 1746490448, 2130698708, 0, 338, 0, 1746490448, 2130698708, 1746489228, 0, 2147090432, 0, 2147090432, 0 <repeats 50 times>}, mask_was_saved = 0}}, priv = {pad = {0x0, 0x0, 0x0, 0x0}, data = {prev = 0x0, cleanup = 0x0, canceltype = 0}}}
        not_first_call = <optimized out>
        robust = <optimized out>
        pagesize_m1 = <optimized out>
        sp = <optimized out>
        freesize = <optimized out>
        __PRETTY_FUNCTION__ = "start_thread"
#9  0x75dcd408 in ?? () at ../sysdeps/unix/sysv/linux/arm/clone.S:86 from /opt/sdk/cebis/sysroots/cortexa9hf-neon-mel-linux-gnueabi/lib/libc.so.6
No locals.
Backtrace stopped: previous frame identical to this frame (corrupt stack?)

Thread 4 (Thread 19007.19010):
#0  0x75ade7a4 in __pthread_cond_wait (cond=0x144a20, mutex=<optimized out>) at /usr/src/debug/glibc/2.24-r0/git/nptl/pthread_cond_wait.c:186
        _a1 = 1329700
        _nr = 240
        _a3tmp = 1
        _a1tmp = 1329700
        _a3 = 1
        _a4tmp = 0
        _a2 = 128
        _a4 = 0
        __ret = <optimized out>
        futex_val = 1
        buffer = {__routine = 0x75ade4f4 <__condvar_cleanup>, __arg = 0x696fed20, __canceltype = 0, __prev = 0x0}
        cbuffer = {oldtype = 0, cond = 0x144a20, mutex = 0x144a08, bc_seq = 0}
        err = <optimized out>
        pshared = 0
        val = <optimized out>
        seq = <optimized out>
#1  0x76044600 in QWaitConditionPrivate::wait (time=4294967295, this=0x144a08) at /usr/src/debug/qtbase/5.9.2+gitAUTOINC+ec16ba393b-r0/git/src/corelib/thread/qwaitcondition_unix.cpp:143
        code = <optimized out>
#2  QWaitCondition::wait (this=this@entry=0x144898, mutex=0x77359400, mutex@entry=0x144894, time=time@entry=4294967295) at /usr/src/debug/qtbase/5.9.2+gitAUTOINC+ec16ba393b-r0/git/src/corelib/thread/qwaitcondition_unix.cpp:215
No locals.
#3  0x76dcdb0c in QSGRenderThreadEventQueue::takeEvent (wait=true, this=0x144890) at /usr/src/debug/qtdeclarative/5.9.2+gitAUTOINC+32218c3243-r0/git/src/quick/scenegraph/qsgthreadedrenderloop.cpp:245
No locals.
#4  QSGRenderThread::processEventsAndWaitForMore (this=this@entry=0x144840) at /usr/src/debug/qtdeclarative/5.9.2+gitAUTOINC+32218c3243-r0/git/src/quick/scenegraph/qsgthreadedrenderloop.cpp:709
No locals.
#5  0x76dce510 in QSGRenderThread::run (this=0x144840) at /usr/src/debug/qtdeclarative/5.9.2+gitAUTOINC+32218c3243-r0/git/src/quick/scenegraph/qsgthreadedrenderloop.cpp:738
No locals.
#6  0x76043488 in QThreadPrivate::start (arg=0x144840) at /usr/src/debug/qtbase/5.9.2+gitAUTOINC+ec16ba393b-r0/git/src/corelib/thread/qthread_unix.cpp:368
        __clframe = {__cancel_routine = 0x760425e0 <QThreadPrivate::finish(void*)>, __cancel_arg = 0x144840, __do_it = 1, __cancel_type = <optimized out>}
        thr = 0x144840
        data = 0x144968
#7  0x75ad7f5c in start_thread (arg=0x696ff450) at /usr/src/debug/glibc/2.24-r0/git/nptl/pthread_create.c:335
        pd = 0x696ff450
        unwind_buf = {cancel_jmp_buf = {{jmp_buf = {-608746651, -948579823, 1768944720, 2130704612, 0, 338, 0, 1768944720, 2130704612, 1768943500, 0 <repeats 54 times>}, mask_was_saved = 0}}, priv = {pad = {0x0, 0x0, 0x0, 0x0}, data = {prev = 0x0, cleanup = 0x0, canceltype = 0}}}
        not_first_call = <optimized out>
        robust = <optimized out>
        pagesize_m1 = <optimized out>
        sp = <optimized out>
        freesize = <optimized out>
        __PRETTY_FUNCTION__ = "start_thread"
#8  0x75dcd408 in ?? () at ../sysdeps/unix/sysv/linux/arm/clone.S:86 from /opt/sdk/cebis/sysroots/cortexa9hf-neon-mel-linux-gnueabi/lib/libc.so.6
No locals.
Backtrace stopped: previous frame identical to this frame (corrupt stack?)

Thread 3 (Thread 19007.19009):
#0  0x75dc4a40 in __GI_ppoll (fds=fds@entry=0x6a300598, nfds=nfds@entry=1, timeout=<optimized out>, timeout@entry=0x0, sigmask=sigmask@entry=0x0) at /usr/src/debug/glibc/2.24-r0/git/sysdeps/unix/sysv/linux/ppoll.c:39
        _a2tmp = 1
        _a2 = 1
        _a3 = 0
        _a1 = 1781532056
        _nr = 336
        _v1tmp = 8
        _a4tmp = 0
        _a1tmp = 1781532056
        _a4 = 0
        _v1 = 8
        _sys_result = <optimized out>
        sc_cancel_oldtype = 0
        sc_ret = <optimized out>
        tval = {tv_sec = 1, tv_nsec = 0}
#1  0x7627a458 in qt_ppoll (timeout_ts=0x0, nfds=1, fds=0x6a300598) at /usr/src/debug/qtbase/5.9.2+gitAUTOINC+ec16ba393b-r0/git/src/corelib/kernel/qcore_unix.cpp:81
No locals.
#2  qt_safe_poll (fds=0x6a300598, nfds=1, timeout_ts=0x0, timeout_ts@entry=0x7627bb5c <QEventDispatcherUNIX::processEvents(QFlags<QEventLoop::ProcessEventsFlag>)+480>) at /usr/src/debug/qtbase/5.9.2+gitAUTOINC+ec16ba393b-r0/git/src/corelib/kernel/qcore_unix.cpp:102
        ret = <optimized out>
        start = {tv_sec = 1781531868, tv_nsec = 1982320812}
        timeout = {tv_sec = 8499, tv_nsec = 837672012}
#3  0x7627bb5c in QEventDispatcherUNIX::processEvents (this=<optimized out>, flags=...) at /usr/src/debug/qtbase/5.9.2+gitAUTOINC+ec16ba393b-r0/git/src/corelib/kernel/qeventdispatcher_unix.cpp:500
        d = 0x6a300480
        include_timers = <optimized out>
        include_notifiers = <optimized out>
        wait_for_events = <optimized out>
        canWait = <optimized out>
        tm = <optimized out>
        wait_tm = {tv_sec = 0, tv_nsec = 0}
        nevents = 0
#4  0x762203f8 in QEventLoop::exec (this=this@entry=0x6aedde00, flags=..., flags@entry=...) at /usr/src/debug/qtbase/5.9.2+gitAUTOINC+ec16ba393b-r0/git/src/corelib/kernel/qeventloop.cpp:212
        d = 0x6a300508
        locker = {val = 1127848}
        ref = {d = 0x6a300508, locker = @0x6aedddb4, exceptionCaught = true}
#5  0x7603e820 in QThread::exec (this=this@entry=0x113420) at /usr/src/debug/qtbase/5.9.2+gitAUTOINC+ec16ba393b-r0/git/src/corelib/thread/qthread.cpp:515
        d = 0x113568
        locker = {val = 1127848}
        eventLoop = {<QObject> = {_vptr.QObject = 0x7647b610 <vtable for QEventLoop+8>, static staticMetaObject = {d = {superdata = 0x0, stringdata = 0x763c8558 <qt_meta_stringdata_QObject>, data = 0x763c86d0 <qt_meta_data_QObject>, static_metacall = 0x76259c08 <QObject::qt_static_metacall(QObject*, QMetaObject::Call, int, void**)>, relatedMetaObjects = 0x0, extradata = 0x0}}, d_ptr = {d = 0x6a300508}, static staticQtMetaObject = {d = {superdata = 0x0, stringdata = 0x763cb344 <qt_meta_stringdata_Qt>, data = 0x763c87e8 <qt_meta_data_Qt>, static_metacall = 0x0, relatedMetaObjects = 0x0, extradata = 0x0}}}, static staticMetaObject = {d = {superdata = 0x22c00 <QObject::staticMetaObject@@Qt_5>, stringdata = 0x763c52d8 <qt_meta_stringdata_QEventLoop>, data = 0x763c5330 <qt_meta_data_QEventLoop>, static_metacall = 0x762200d8 <QEventLoop::qt_static_metacall(QObject*, QMetaObject::Call, int, void**)>, relatedMetaObjects = 0x0, extradata = 0x0}}}
        returnCode = <optimized out>
#6  0x7673c518 in QQmlThreadPrivate::run (this=0x113420) at /usr/src/debug/qtdeclarative/5.9.2+gitAUTOINC+32218c3243-r0/git/src/qml/qml/ftw/qqmlthread.cpp:147
No locals.
#7  0x76043488 in QThreadPrivate::start (arg=0x113420) at /usr/src/debug/qtbase/5.9.2+gitAUTOINC+ec16ba393b-r0/git/src/corelib/thread/qthread_unix.cpp:368
        __clframe = {__cancel_routine = 0x760425e0 <QThreadPrivate::finish(void*)>, __cancel_arg = 0x113420, __do_it = 1, __cancel_type = <optimized out>}
        thr = 0x113420
        data = 0x113628
#8  0x75ad7f5c in start_thread (arg=0x6aede450) at /usr/src/debug/glibc/2.24-r0/git/nptl/pthread_create.c:335
        pd = 0x6aede450
        unwind_buf = {cancel_jmp_buf = {{jmp_buf = {-667585691, -948579823, 1793975376, 2130705148, 0, 338, 0, 1793975376, 2130705148, 1793974156, 0 <repeats 54 times>}, mask_was_saved = 0}}, priv = {pad = {0x0, 0x0, 0x0, 0x0}, data = {prev = 0x0, cleanup = 0x0, canceltype = 0}}}
        not_first_call = <optimized out>
        robust = <optimized out>
        pagesize_m1 = <optimized out>
        sp = <optimized out>
        freesize = <optimized out>
        __PRETTY_FUNCTION__ = "start_thread"
#9  0x75dcd408 in ?? () at ../sysdeps/unix/sysv/linux/arm/clone.S:86 from /opt/sdk/cebis/sysroots/cortexa9hf-neon-mel-linux-gnueabi/lib/libc.so.6
No locals.
Backtrace stopped: previous frame identical to this frame (corrupt stack?)

Thread 2 (Thread 19007.19008):
#0  wl_proxy_add_listener (proxy=0x0, implementation=0x755ea1cc <gcsWL_FRAME_LISTENER>, data=data@entry=0x662fef64) at /usr/src/debug/wayland/1.9.0-r0/wayland-1.9.0/src/wayland-client.c:464
No locals.
#1  0x755db544 in wl_callback_add_listener (data=0x662fef64, listener=0x755ea1cc <gcsWL_FRAME_LISTENER>, wl_callback=<optimized out>) at /home/bamboo/automation/3.14.52-1.1.1/graphics_pkg/temp_build_dir/build-imx6qsabresd/tmp/sysroots/imx6qsabresd/usr/include/wayland-client-protocol.h:317
No locals.
#2  gcoOS_SetDisplayVirtualEx (Display=<optimized out>, Window=0x662fee84, Context=0x662fef64, Surface=<optimized out>, Offset=0, X=0, Y=0) at gc_hal_user_wayland.c:1692
        swapInterval = -1
        ret = <optimized out>
        i = <optimized out>
        wl_window = 0x662fee84
        egl_buffer = 0x662fef64
        wl_buffer = 0x662d1538
        display = 0x35d80
#3  0x7550c3ac in veglSetDisplayFlip (Display=Display@entry=0x11004c, Surface=<optimized out>, BackBuffer=BackBuffer@entry=0x6636c474) at gc_egl_platform.c:249
        status = <optimized out>
#4  0x75506c6c in veglSwapWorker (Display=0x11004c) at gc_egl_swap.c:741
        display = 0x11004c
        displayWorker = 0x6636c464
        currWorker = 0x6636c464
        bStop = 0
        __user_ptr__ = <synthetic pointer>
#5  0x75ad7f5c in start_thread (arg=0x6b6de450) at /usr/src/debug/glibc/2.24-r0/git/nptl/pthread_create.c:335
        pd = 0x6b6de450
        unwind_buf = {cancel_jmp_buf = {{jmp_buf = {-642419867, -948579823, 1802363984, 2130704688, 0, 338, 0, 0, 2130704688, 1802362764, 0 <repeats 54 times>}, mask_was_saved = 0}}, priv = {pad = {0x0, 0x0, 0x0, 0x0}, data = {prev = 0x0, cleanup = 0x0, canceltype = 0}}}
        not_first_call = <optimized out>
        robust = <optimized out>
        pagesize_m1 = <optimized out>
        sp = <optimized out>
        freesize = <optimized out>
        __PRETTY_FUNCTION__ = "start_thread"
#6  0x75dcd408 in ?? () at ../sysdeps/unix/sysv/linux/arm/clone.S:86 from /opt/sdk/cebis/sysroots/cortexa9hf-neon-mel-linux-gnueabi/lib/libc.so.6
No locals.
Backtrace stopped: previous frame identical to this frame (corrupt stack?)

Thread 1 (Thread 19007.19007):
#0  0x75d994c4 in nanosleep () at ../sysdeps/unix/syscall-template.S:84
No locals.
#1  0x75dc7420 in usleep (useconds=useconds@entry=10000) at /usr/src/debug/glibc/2.24-r0/git/sysdeps/posix/usleep.c:32
        ts = {tv_sec = 0, tv_nsec = 10000000}
#2  0x755d7574 in gcoOS_Delay (Os=Os@entry=0x0, Delay=Delay@entry=10) at gc_hal_user_os.c:4033
        __user__ = 1 '\001'
        __user_ptr__ = <synthetic pointer>
#3  0x75503cf8 in _DestroySurfaceObjects (Thread=Thread@entry=0x3e2f4, Surface=Surface@entry=0x6636bc7c) at gc_egl_surface.c:1123
        i = <optimized out>
        status = gcvSTATUS_OK
#4  0x75503f80 in _DestroySurface (Thread=Thread@entry=0x3e2f4, Surface=Surface@entry=0x6636bc7c) at gc_egl_surface.c:2316
No locals.
#5  0x75504004 in veglDereferenceSurface (Thread=Thread@entry=0x3e2f4, Surface=Surface@entry=0x6636bc7c, Always=Always@entry=0) at gc_egl_surface.c:2598
        reference = 1
        __user__ = 1 '\001'
        __user_ptr__ = <synthetic pointer>
#6  0x755049bc in veglDestroySurface (Dpy=Dpy@entry=0x11004c, Surface=Surface@entry=0x6636bc7c) at gc_egl_surface.c:3323
        thread = 0x3e2f4
        dpy = 0x11004c
        surface = 0x6636bc7c
        status = <optimized out>
        __user__ = 1 '\001'
        __user_ptr__ = <synthetic pointer>
#7  0x75504ad0 in eglDestroySurface (Dpy=0x11004c, Surface=0x6636bc7c) at gc_egl_surface.c:3362
        ret = <optimized out>
        __FUNCTION__ = "eglDestroySurface"
#8  0x737f6d5c in QtWaylandClient::QWaylandEglWindow::~QWaylandEglWindow (this=0x46b7b0, __in_chrg=<optimized out>) at /usr/src/debug/qtwayland/5.9.2+gitAUTOINC+d483ed2927-r0/git/src/hardwareintegration/client/wayland-egl/qwaylandeglwindow.cpp:80
No locals.
#9  0x737f6dc8 in QtWaylandClient::QWaylandEglWindow::~QWaylandEglWindow (this=0x46b7b0, __in_chrg=<optimized out>) at /usr/src/debug/qtwayland/5.9.2+gitAUTOINC+d483ed2927-r0/git/src/hardwareintegration/client/wayland-egl/qwaylandeglwindow.cpp:88
No locals.
#10 0x768d3e88 in QWindowPrivate::destroy (this=0x2df430) at /usr/src/debug/qtbase/5.9.2+gitAUTOINC+ec16ba393b-r0/git/src/gui/kernel/qwindow.cpp:1835
        childrenWindows = {<QListSpecialMethods<QObject*>> = {<No data fields>}, {p = {static shared_null = {ref = {atomic = {_q_value = {<std::__atomic_base<int>> = {static _S_alignment = 4, _M_i = -1}, <No data fields>}}}, alloc = 0, begin = 0, end = 0, array = {0x0}}, d = 0x93bfe0}, d = 0x93bfe0}}
        wasVisible = <optimized out>
        e = {<QEvent> = {_vptr.QEvent = 0x76c665b8 <vtable for QPlatformSurfaceEvent+8>, static staticMetaObject = {d = {superdata = 0x0, stringdata = 0x763c62bc <qt_meta_stringdata_QEvent>, data = 0x763c5d10 <qt_meta_data_QEvent>, static_metacall = 0x0, relatedMetaObjects = 0x0, extradata = 0x0}}, d = 0x0, t = 217, posted = 0, spont = 0, m_accept = 1, reserved = 15}, m_surfaceEventType = QPlatformSurfaceEvent::SurfaceAboutToBeDestroyed}
        this = 0x2df430
#11 0x768d5a54 in QWindow::event (this=this@entry=0x2df418, ev=ev@entry=0x7efff81c) at /usr/src/debug/qtbase/5.9.2+gitAUTOINC+ec16ba393b-r0/git/src/gui/kernel/qwindow.cpp:2234
No locals.
#12 0x76e23998 in QQuickWindow::event (this=0x2df418, e=0x7efff81c) at /usr/src/debug/qtdeclarative/5.9.2+gitAUTOINC+32218c3243-r0/git/src/quick/items/qquickwindow.cpp:1606
No locals.
#13 0x76221f50 in doNotify (event=<optimized out>, receiver=<optimized out>) at /usr/src/debug/qtbase/5.9.2+gitAUTOINC+ec16ba393b-r0/git/src/corelib/kernel/qcoreapplication.cpp:1093
No locals.
#14 QCoreApplication::notify (this=<optimized out>, receiver=<optimized out>, event=<optimized out>) at /usr/src/debug/qtbase/5.9.2+gitAUTOINC+ec16ba393b-r0/git/src/corelib/kernel/qcoreapplication.cpp:1079
No locals.
#15 0x762220c8 in QCoreApplication::notifyInternal2 (receiver=0x2df418, event=event@entry=0x7efff81c) at /usr/src/debug/qtbase/5.9.2+gitAUTOINC+ec16ba393b-r0/git/src/corelib/kernel/qcoreapplication.cpp:1018
        selfRequired = <optimized out>
        result = false
        cbdata = {0x2df418, 0x7efff81c, 0x7efff7eb}
        d = <optimized out>
        threadData = 0x28500
        scopeLevelCounter = {threadData = 0x28500}
#16 0x768c6af8 in QCoreApplication::sendSpontaneousEvent (event=0x7efff81c, receiver=<optimized out>) at /usr/src/debug/qtbase/5.9.2+gitAUTOINC+ec16ba393b-r0/git/src/corelib/kernel/qcoreapplication.h:236
No locals.
#17 QGuiApplicationPrivate::processCloseEvent (e=0x93b850) at /usr/src/debug/qtbase/5.9.2+gitAUTOINC+ec16ba393b-r0/git/src/gui/kernel/qguiapplication.cpp:2276
        event = {<QEvent> = {_vptr.QEvent = 0x76c665d8 <vtable for QCloseEvent+8>, static staticMetaObject = {d = {superdata = 0x0, stringdata = 0x763c62bc <qt_meta_stringdata_QEvent>, data = 0x763c5d10 <qt_meta_data_QEvent>, static_metacall = 0x0, relatedMetaObjects = 0x0, extradata = 0x0}}, d = 0x0, t = 19, posted = 0, spont = 1, m_accept = 1, reserved = 0}, <No data fields>}
        e = 0x93b850
#18 0x768cb2ac in QGuiApplicationPrivate::processWindowSystemEvent (e=e@entry=0x93b850) at /usr/src/debug/qtbase/5.9.2+gitAUTOINC+ec16ba393b-r0/git/src/gui/kernel/qguiapplication.cpp:1772
No locals.
#19 0x768a48fc in QWindowSystemInterface::sendWindowSystemEvents (flags=..., flags@entry=...) at /usr/src/debug/qtbase/5.9.2+gitAUTOINC+ec16ba393b-r0/git/src/gui/kernel/qwindowsysteminterface.cpp:939
        event = 0x93b850
        nevents = 1
#20 0x768a4b60 in QWindowSystemInterface::flushWindowSystemEvents (flags=flags@entry=...) at /usr/src/debug/qtbase/5.9.2+gitAUTOINC+ec16ba393b-r0/git/src/gui/kernel/qwindowsysteminterface.cpp:908
No locals.
#21 0x768d0c04 in QWindow::close (this=0x2df418) at /usr/src/debug/qtbase/5.9.2+gitAUTOINC+ec16ba393b-r0/git/src/gui/kernel/qwindow.cpp:2085
        accepted = false
        this = 0x2df418
#22 0x00011c68 in Proxy::<lambda()>::operator() (__closure=0x93cab0) at /opt/tbsw/bug-testcases/crash-wayland-client-sync/client/proxy.cpp:24
        this = 0x34d00
#23 QtPrivate::FunctorCall<QtPrivate::IndexesList<>, QtPrivate::List<>, void, Proxy::killLatestWindow()::<lambda()> >::call (arg=0x7efff8fc, f=...) at /opt/sdk/cebis/sysroots/cortexa9hf-neon-mel-linux-gnueabi/usr/include/qt5/QtCore/qobjectdefs_impl.h:130
No locals.
#24 QtPrivate::Functor<Proxy::killLatestWindow()::<lambda()>, 0>::call<QtPrivate::List<>, void> (arg=0x7efff8fc, f=...) at /opt/sdk/cebis/sysroots/cortexa9hf-neon-mel-linux-gnueabi/usr/include/qt5/QtCore/qobjectdefs_impl.h:240
No locals.
#25 QtPrivate::QFunctorSlotObject<Proxy::killLatestWindow()::<lambda()>, 0, QtPrivate::List<>, void>::impl(int, QtPrivate::QSlotObjectBase *, QObject *, void **, bool *) (which=which@entry=1, this_=0x93caa8, r=<optimized out>, a=a@entry=0x7efff91c, ret=ret@entry=0x0) at /opt/sdk/cebis/sysroots/cortexa9hf-neon-mel-linux-gnueabi/usr/include/qt5/QtCore/qobject_impl.h:168
No locals.
#26 0x7625efd0 in QtPrivate::QSlotObjectBase::call (a=0x7efff91c, r=<optimized out>, this=<optimized out>) at /usr/src/debug/qtbase/5.9.2+gitAUTOINC+ec16ba393b-r0/git/src/corelib/kernel/qobject_impl.h:101
No locals.
#27 QSingleShotTimer::timerEvent (this=0x3aa160) at /usr/src/debug/qtbase/5.9.2+gitAUTOINC+ec16ba393b-r0/git/src/corelib/kernel/qtimer.cpp:318
        args = {0x0}
#28 0x76252ff8 in QObject::event (this=0x3aa160, e=<optimized out>) at /usr/src/debug/qtbase/5.9.2+gitAUTOINC+ec16ba393b-r0/git/src/corelib/kernel/qobject.cpp:1268
No locals.
#29 0x76221f50 in doNotify (event=<optimized out>, receiver=<optimized out>) at /usr/src/debug/qtbase/5.9.2+gitAUTOINC+ec16ba393b-r0/git/src/corelib/kernel/qcoreapplication.cpp:1093
No locals.
#30 QCoreApplication::notify (this=<optimized out>, receiver=<optimized out>, event=<optimized out>) at /usr/src/debug/qtbase/5.9.2+gitAUTOINC+ec16ba393b-r0/git/src/corelib/kernel/qcoreapplication.cpp:1079
No locals.
#31 0x762220c8 in QCoreApplication::notifyInternal2 (receiver=0x3aa160, event=event@entry=0x7efffa98) at /usr/src/debug/qtbase/5.9.2+gitAUTOINC+ec16ba393b-r0/git/src/corelib/kernel/qcoreapplication.cpp:1018
        selfRequired = <optimized out>
        result = false
        cbdata = {0x3aa160, 0x7efffa98, 0x7efffa3b}
        d = <optimized out>
        threadData = 0x28500
        scopeLevelCounter = {threadData = 0x28500}
#32 0x7627def4 in QCoreApplication::sendEvent (event=0x7efffa98, receiver=<optimized out>) at /usr/src/debug/qtbase/5.9.2+gitAUTOINC+ec16ba393b-r0/git/src/corelib/kernel/qcoreapplication.h:233
No locals.
#33 QTimerInfoList::activateTimers (this=this@entry=0x344b4) at /usr/src/debug/qtbase/5.9.2+gitAUTOINC+ec16ba393b-r0/git/src/corelib/kernel/qtimerinfo_unix.cpp:643
        e = {<QEvent> = {_vptr.QEvent = 0x7647b734 <vtable for QTimerEvent+8>, static staticMetaObject = {d = {superdata = 0x0, stringdata = 0x763c62bc <qt_meta_stringdata_QEvent>, data = 0x763c5d10 <qt_meta_data_QEvent>, static_metacall = 0x0, relatedMetaObjects = 0x0, extradata = 0x0}}, d = 0x0, t = 1, posted = 0, spont = 0, m_accept = 1, reserved = 4063}, id = 2}
        currentTimerInfo = 0x0
        n_act = 1
        maxCount = <optimized out>
        currentTime = {tv_sec = 8526, tv_nsec = 0}
#34 0x7627b010 in QEventDispatcherUNIXPrivate::activateTimers (this=this@entry=0x34458) at /usr/src/debug/qtbase/5.9.2+gitAUTOINC+ec16ba393b-r0/git/src/corelib/kernel/qeventdispatcher_unix.cpp:249
No locals.
#35 0x7627bd74 in QEventDispatcherUNIX::processEvents (this=<optimized out>, flags=...) at /usr/src/debug/qtbase/5.9.2+gitAUTOINC+ec16ba393b-r0/git/src/corelib/kernel/qeventdispatcher_unix.cpp:514
        d = 0x34458
        include_timers = <optimized out>
        include_notifiers = <optimized out>
        wait_for_events = <optimized out>
        canWait = <optimized out>
        tm = <optimized out>
        wait_tm = {tv_sec = 0, tv_nsec = 5000000}
        nevents = 0
#36 0x73ada420 in QUnixEventDispatcherQPA::processEvents (this=<optimized out>, flags=...) at /usr/src/debug/qtbase/5.9.2+gitAUTOINC+ec16ba393b-r0/git/src/platformsupport/eventdispatchers/qunixeventdispatcher.cpp:68
        didSendEvents = 152
#37 0x762203f8 in QEventLoop::exec (this=this@entry=0x7efffb98, flags=..., flags@entry=...) at /usr/src/debug/qtbase/5.9.2+gitAUTOINC+ec16ba393b-r0/git/src/corelib/kernel/qeventloop.cpp:212
        d = 0x112888
        locker = {val = 166328}
        ref = {d = 0x112888, locker = @0x7efffb4c, exceptionCaught = true}
#38 0x76229698 in QCoreApplication::exec () at /usr/src/debug/qtbase/5.9.2+gitAUTOINC+ec16ba393b-r0/git/src/corelib/kernel/qcoreapplication.cpp:1291
        threadData = 0x28500
        eventLoop = {<QObject> = {_vptr.QObject = 0x7647b610 <vtable for QEventLoop+8>, static staticMetaObject = {d = {superdata = 0x0, stringdata = 0x763c8558 <qt_meta_stringdata_QObject>, data = 0x763c86d0 <qt_meta_data_QObject>, static_metacall = 0x76259c08 <QObject::qt_static_metacall(QObject*, QMetaObject::Call, int, void**)>, relatedMetaObjects = 0x0, extradata = 0x0}}, d_ptr = {d = 0x112888}, static staticQtMetaObject = {d = {superdata = 0x0, stringdata = 0x763cb344 <qt_meta_stringdata_Qt>, data = 0x763c87e8 <qt_meta_data_Qt>, static_metacall = 0x0, relatedMetaObjects = 0x0, extradata = 0x0}}}, static staticMetaObject = {d = {superdata = 0x22c00 <QObject::staticMetaObject@@Qt_5>, stringdata = 0x763c52d8 <qt_meta_stringdata_QEventLoop>, data = 0x763c5330 <qt_meta_data_QEventLoop>, static_metacall = 0x762200d8 <QEventLoop::qt_static_metacall(QObject*, QMetaObject::Call, int, void**)>, relatedMetaObjects = 0x0, extradata = 0x0}}}
        returnCode = <optimized out>
#39 0x768c113c in QGuiApplication::exec () at /usr/src/debug/qtbase/5.9.2+gitAUTOINC+ec16ba393b-r0/git/src/gui/kernel/qguiapplication.cpp:1679
No locals.
#40 0x00011790 in main (argc=<optimized out>, argv=<optimized out>) at /opt/tbsw/bug-testcases/crash-wayland-client-sync/client/main.cpp:19
        app = {<QCoreApplication> = {<QObject> = {_vptr.QObject = 0x76c66140 <vtable for QGuiApplication+8>, static staticMetaObject = {d = {superdata = 0x0, stringdata = 0x763c8558 <qt_meta_stringdata_QObject>, data = 0x763c86d0 <qt_meta_data_QObject>, static_metacall = 0x76259c08 <QObject::qt_static_metacall(QObject*, QMetaObject::Call, int, void**)>, relatedMetaObjects = 0x0, extradata = 0x0}}, d_ptr = {d = 0x28468}, static staticQtMetaObject = {d = {superdata = 0x0, stringdata = 0x763cb344 <qt_meta_stringdata_Qt>, data = 0x763c87e8 <qt_meta_data_Qt>, static_metacall = 0x0, relatedMetaObjects = 0x0, extradata = 0x0}}}, static staticMetaObject = {d = {superdata = 0x22c00 <QObject::staticMetaObject@@Qt_5>, stringdata = 0x763c5538 <qt_meta_stringdata_QCoreApplication>, data = 0x763c5718 <qt_meta_data_QCoreApplication>, static_metacall = 0x76223bfc <QCoreApplication::qt_static_metacall(QObject*, QMetaObject::Call, int, void**)>, relatedMetaObjects = 0x0, extradata = 0x0}}, static self = 0x7efffbdc}, static staticMetaObject = {d = {superdata = 0x7647b6cc <QCoreApplication::staticMetaObject>, stringdata = 0x76c1f3a0 <qt_meta_stringdata_QGuiApplication>, data = 0x76c1f7b8 <qt_meta_data_QGuiApplication>, static_metacall = 0x768cb3e0 <QGuiApplication::qt_static_metacall(QObject*, QMetaObject::Call, int, void**)>, relatedMetaObjects = 0x0, extradata = 0x0}}}
        proxy = <optimized out>
        view = {<QQuickWindow> = {<QWindow> = {<QObject> = {_vptr.QObject = 0x76fc3240 <vtable for QQuickView+8>, static staticMetaObject = {d = {superdata = 0x0, stringdata = 0x763c8558 <qt_meta_stringdata_QObject>, data = 0x763c86d0 <qt_meta_data_QObject>, static_metacall = 0x76259c08 <QObject::qt_static_metacall(QObject*, QMetaObject::Call, int, void**)>, relatedMetaObjects = 0x0, extradata = 0x0}}, d_ptr = {d = 0x35770}, static staticQtMetaObject = {d = {superdata = 0x0, stringdata = 0x763cb344 <qt_meta_stringdata_Qt>, data = 0x763c87e8 <qt_meta_data_Qt>, static_metacall = 0x0, relatedMetaObjects = 0x0, extradata = 0x0}}}, <QSurface> = {_vptr.QSurface = 0x76fc32d4 <vtable for QQuickView+156>, m_type = QSurface::Window, m_reserved = 0x0}, static staticMetaObject = {d = {superdata = 0x22c00 <QObject::staticMetaObject@@Qt_5>, stringdata = 0x76c1fd88 <qt_meta_stringdata_QWindow>, data = 0x76c206b0 <qt_meta_data_QWindow>, static_metacall = 0x768d4b34 <QWindow::qt_static_metacall(QObject*, QMetaObject::Call, int, void**)>, relatedMetaObjects = 0x0, extradata = 0x0}}}, static staticMetaObject = {d = {superdata = 0x76c662cc <QWindow::staticMetaObject>, stringdata = 0x76f7951c <qt_meta_stringdata_QQuickWindow>, data = 0x76f79acc <qt_meta_data_QQuickWindow>, static_metacall = 0x76e19fa8 <QQuickWindow::qt_static_metacall(QObject*, QMetaObject::Call, int, void**)>, relatedMetaObjects = 0x0, extradata = 0x0}}}, static staticMetaObject = {d = {superdata = 0x76fbf584 <QQuickWindow::staticMetaObject>, stringdata = 0x76f88d98 <qt_meta_stringdata_QQuickView>, data = 0x76f89000 <qt_meta_data_QQuickView>, static_metacall = 0x76ea47cc <QQuickView::qt_static_metacall(QObject*, QMetaObject::Call, int, void**)>, relatedMetaObjects = 0x0, extradata = 0x0}}}


