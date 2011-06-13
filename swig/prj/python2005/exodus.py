# This file was automatically generated by SWIG (http://www.swig.org).
# Version 2.0.4
#
# Do not make changes to this file unless you know what you are doing--modify
# the SWIG interface file instead.


"""
An interface to Exodus.
"""


from sys import version_info
if version_info >= (2,6,0):
    def swig_import_helper():
        from os.path import dirname
        import imp
        fp = None
        try:
            fp, pathname, description = imp.find_module('_exodus', [dirname(__file__)])
        except ImportError:
            import _exodus
            return _exodus
        if fp is not None:
            try:
                _mod = imp.load_module('_exodus', fp, pathname, description)
            finally:
                fp.close()
            return _mod
    _exodus = swig_import_helper()
    del swig_import_helper
else:
    import _exodus
del version_info
try:
    _swig_property = property
except NameError:
    pass # Python < 2.2 doesn't have 'property'.
def _swig_setattr_nondynamic(self,class_type,name,value,static=1):
    if (name == "thisown"): return self.this.own(value)
    if (name == "this"):
        if type(value).__name__ == 'SwigPyObject':
            self.__dict__[name] = value
            return
    method = class_type.__swig_setmethods__.get(name,None)
    if method: return method(self,value)
    if (not static):
        self.__dict__[name] = value
    else:
        raise AttributeError("You cannot add attributes to %s" % self)

def _swig_setattr(self,class_type,name,value):
    return _swig_setattr_nondynamic(self,class_type,name,value,0)

def _swig_getattr(self,class_type,name):
    if (name == "thisown"): return self.this.own()
    method = class_type.__swig_getmethods__.get(name,None)
    if method: return method(self)
    raise AttributeError(name)

def _swig_repr(self):
    try: strthis = "proxy of " + self.this.__repr__()
    except: strthis = ""
    return "<%s.%s; %s >" % (self.__class__.__module__, self.__class__.__name__, strthis,)

try:
    _object = object
    _newclass = 1
except AttributeError:
    class _object : pass
    _newclass = 0


MV_H = _exodus.MV_H
LASTDELIMITERCHARNOPLUS1 = _exodus.LASTDELIMITERCHARNOPLUS1
class var(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, var, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, var, name)
    __swig_destroy__ = _exodus.delete_var
    __del__ = lambda self : None;
    def toBool(self): return _exodus.var_toBool(self)
    def toInt(self): return _exodus.var_toInt(self)
    def toDouble(self): return _exodus.var_toDouble(self)
    def towstring(self): return _exodus.var_towstring(self)
    def __repr__(self): return _exodus.var___repr__(self)
    def __init__(self, *args): 
        this = _exodus.new_var(*args)
        try: self.this.append(this)
        except: self.this = this
    def __nonzero__(self):
        return _exodus.var___nonzero__(self)
    __bool__ = __nonzero__


    def __call__(self, *args): return _exodus.var___call__(self, *args)
    def __ixor__(self, *args): return _exodus.var___ixor__(self, *args)
    def __iadd__(self, *args): return _exodus.var___iadd__(self, *args)
    def __isub__(self, *args): return _exodus.var___isub__(self, *args)
    def date(self): return _exodus.var_date(self)
    def time(self): return _exodus.var_time(self)
    def timedate(self): return _exodus.var_timedate(self)
    def ossleep(self, *args): return _exodus.var_ossleep(self, *args)
    def ostime(self): return _exodus.var_ostime(self)
    def osopen(self, *args): return _exodus.var_osopen(self, *args)
    def osbread(self, *args): return _exodus.var_osbread(self, *args)
    def osbwrite(self, *args): return _exodus.var_osbwrite(self, *args)
    def osclose(self): return _exodus.var_osclose(self)
    def oswrite(self, *args): return _exodus.var_oswrite(self, *args)
    def osdelete(self, *args): return _exodus.var_osdelete(self, *args)
    def osrename(self, *args): return _exodus.var_osrename(self, *args)
    def oscopy(self, *args): return _exodus.var_oscopy(self, *args)
    def oslist(self, *args): return _exodus.var_oslist(self, *args)
    def oslistf(self, *args): return _exodus.var_oslistf(self, *args)
    def oslistd(self, *args): return _exodus.var_oslistd(self, *args)
    def osfile(self): return _exodus.var_osfile(self)
    def osdir(self): return _exodus.var_osdir(self)
    def osmkdir(self): return _exodus.var_osmkdir(self)
    def osrmdir(self, evenifnotempty = False): return _exodus.var_osrmdir(self, evenifnotempty)
    def oscwd(self, *args): return _exodus.var_oscwd(self, *args)
    def osflush(self): return _exodus.var_osflush(self)
    def osread(self, *args): return _exodus.var_osread(self, *args)
    def suspend(self): return _exodus.var_suspend(self)
    def osshell(self): return _exodus.var_osshell(self)
    def osshellread(self): return _exodus.var_osshellread(self)
    def osshellwrite(self, *args): return _exodus.var_osshellwrite(self, *args)
    def osgetenv(self, *args): return _exodus.var_osgetenv(self, *args)
    def ossetenv(self, *args): return _exodus.var_ossetenv(self, *args)
    def stop(self, *args): return _exodus.var_stop(self, *args)
    def abort(self, *args): return _exodus.var_abort(self, *args)
    def perform(self): return _exodus.var_perform(self)
    def execute(self): return _exodus.var_execute(self)
    def chain(self): return _exodus.var_chain(self)
    def logoff(self): return _exodus.var_logoff(self)
    def debug(self, *args): return _exodus.var_debug(self, *args)
    def breakon(self): return _exodus.var_breakon(self)
    def breakoff(self): return _exodus.var_breakoff(self)
    def output(self, *args): return _exodus.var_output(self, *args)
    def outputl(self, *args): return _exodus.var_outputl(self, *args)
    def outputt(self, *args): return _exodus.var_outputt(self, *args)
    def logput(self, *args): return _exodus.var_logput(self, *args)
    def logputl(self, *args): return _exodus.var_logputl(self, *args)
    def errput(self, *args): return _exodus.var_errput(self, *args)
    def errputl(self, *args): return _exodus.var_errputl(self, *args)
    def put(self, *args): return _exodus.var_put(self, *args)
    def at(self, *args): return _exodus.var_at(self, *args)
    def getcursor(self): return _exodus.var_getcursor(self)
    def setcursor(self): return _exodus.var_setcursor(self)
    def getprompt(self): return _exodus.var_getprompt(self)
    def setprompt(self): return _exodus.var_setprompt(self)
    def input(self, *args): return _exodus.var_input(self, *args)
    def eof(self): return _exodus.var_eof(self)
    def assigned(self): return _exodus.var_assigned(self)
    def unassigned(self): return _exodus.var_unassigned(self)
    def transfer(self, *args): return _exodus.var_transfer(self, *args)
    def exchange(self, *args): return _exodus.var_exchange(self, *args)
    def clone(self, *args): return _exodus.var_clone(self, *args)
    def abs(self): return _exodus.var_abs(self)
    def mod(self, *args): return _exodus.var_mod(self, *args)
    def pwr(self, *args): return _exodus.var_pwr(self, *args)
    def rnd(self): return _exodus.var_rnd(self)
    def initrnd(self): return _exodus.var_initrnd(self)
    def exp(self): return _exodus.var_exp(self)
    def sqrt(self): return _exodus.var_sqrt(self)
    def sin(self): return _exodus.var_sin(self)
    def cos(self): return _exodus.var_cos(self)
    def tan(self): return _exodus.var_tan(self)
    def atan(self): return _exodus.var_atan(self)
    def loge(self): return _exodus.var_loge(self)
    def integer(self): return _exodus.var_integer(self)
    def floor(self): return _exodus.var_floor(self)
    def round(self, ndecimals = 0): return _exodus.var_round(self, ndecimals)
    def setxlocale(self): return _exodus.var_setxlocale(self)
    def getxlocale(self): return _exodus.var_getxlocale(self)
    def chr(self, *args): return _exodus.var_chr(self, *args)
    def str(self, *args): return _exodus.var_str(self, *args)
    def space(self): return _exodus.var_space(self)
    def match(self, *args): return _exodus.var_match(self, *args)
    def seq(self): return _exodus.var_seq(self)
    def dcount(self, *args): return _exodus.var_dcount(self, *args)
    def count(self, *args): return _exodus.var_count(self, *args)
    def length(self): return _exodus.var_length(self)
    def len(self): return _exodus.var_len(self)
    def data(self): return _exodus.var_data(self)
    def isnum(self): return _exodus.var_isnum(self)
    def isnum_old(self): return _exodus.var_isnum_old(self)
    def converter(self, *args): return _exodus.var_converter(self, *args)
    def swapper(self, *args): return _exodus.var_swapper(self, *args)
    def splicer(self, *args): return _exodus.var_splicer(self, *args)
    def quoter(self): return _exodus.var_quoter(self)
    def squoter(self): return _exodus.var_squoter(self)
    def unquoter(self): return _exodus.var_unquoter(self)
    def ucaser(self): return _exodus.var_ucaser(self)
    def lcaser(self): return _exodus.var_lcaser(self)
    def trimmer(self, *args): return _exodus.var_trimmer(self, *args)
    def trimmerf(self, *args): return _exodus.var_trimmerf(self, *args)
    def trimmerb(self, *args): return _exodus.var_trimmerb(self, *args)
    def fieldstorer(self, *args): return _exodus.var_fieldstorer(self, *args)
    def substrer(self, *args): return _exodus.var_substrer(self, *args)
    def convert(self, *args): return _exodus.var_convert(self, *args)
    def swap(self, *args): return _exodus.var_swap(self, *args)
    def splice(self, *args): return _exodus.var_splice(self, *args)
    def quote(self): return _exodus.var_quote(self)
    def squote(self): return _exodus.var_squote(self)
    def unquote(self): return _exodus.var_unquote(self)
    def ucase(self): return _exodus.var_ucase(self)
    def lcase(self): return _exodus.var_lcase(self)
    def trim(self, *args): return _exodus.var_trim(self, *args)
    def trimf(self, *args): return _exodus.var_trimf(self, *args)
    def trimb(self, *args): return _exodus.var_trimb(self, *args)
    def fieldstore(self, *args): return _exodus.var_fieldstore(self, *args)
    def substr(self, *args): return _exodus.var_substr(self, *args)
    def index(self, *args): return _exodus.var_index(self, *args)
    def index2(self, *args): return _exodus.var_index2(self, *args)
    def field(self, *args): return _exodus.var_field(self, *args)
    def field2(self, *args): return _exodus.var_field2(self, *args)
    def oconv(self, *args): return _exodus.var_oconv(self, *args)
    def iconv(self, *args): return _exodus.var_iconv(self, *args)
    def lower(self): return _exodus.var_lower(self)
    def _raise(self): return _exodus.var__raise(self)
    def crop(self): return _exodus.var_crop(self)
    def lowerer(self): return _exodus.var_lowerer(self)
    def raiser(self): return _exodus.var_raiser(self)
    def cropper(self): return _exodus.var_cropper(self)
    def remove(self, *args): return _exodus.var_remove(self, *args)
    def replace(self, *args): return _exodus.var_replace(self, *args)
    def insert(self, *args): return _exodus.var_insert(self, *args)
    def erase(self, *args): return _exodus.var_erase(self, *args)
    def extract(self, *args): return _exodus.var_extract(self, *args)
    def replacer(self, *args): return _exodus.var_replacer(self, *args)
    def inserter(self, *args): return _exodus.var_inserter(self, *args)
    def eraser(self, *args): return _exodus.var_eraser(self, *args)
    def locate(self, *args): return _exodus.var_locate(self, *args)
    def locateby(self, *args): return _exodus.var_locateby(self, *args)
    def locateusing(self, *args): return _exodus.var_locateusing(self, *args)
    def sum(self, *args): return _exodus.var_sum(self, *args)
    def connect(self, *args): return _exodus.var_connect(self, *args)
    def disconnect(self): return _exodus.var_disconnect(self)
    def setdefaultconnection(self): return _exodus.var_setdefaultconnection(self)
    def begintrans(self): return _exodus.var_begintrans(self)
    def rollbacktrans(self): return _exodus.var_rollbacktrans(self)
    def committrans(self): return _exodus.var_committrans(self)
    def createdb(self, *args): return _exodus.var_createdb(self, *args)
    def deletedb(self, *args): return _exodus.var_deletedb(self, *args)
    def createfile(self, *args): return _exodus.var_createfile(self, *args)
    def deletefile(self): return _exodus.var_deletefile(self)
    def clearfile(self): return _exodus.var_clearfile(self)
    def listfiles(self): return _exodus.var_listfiles(self)
    def createindex(self, *args): return _exodus.var_createindex(self, *args)
    def deleteindex(self, *args): return _exodus.var_deleteindex(self, *args)
    def listindexes(self, *args): return _exodus.var_listindexes(self, *args)
    def open(self, *args): return _exodus.var_open(self, *args)
    def close(self): return _exodus.var_close(self)
    def select(self, *args): return _exodus.var_select(self, *args)
    def clearselect(self): return _exodus.var_clearselect(self)
    def readnext(self, *args): return _exodus.var_readnext(self, *args)
    def selectrecord(self, *args): return _exodus.var_selectrecord(self, *args)
    def readnextrecord(self, *args): return _exodus.var_readnextrecord(self, *args)
    def lock(self, *args): return _exodus.var_lock(self, *args)
    def unlock(self, *args): return _exodus.var_unlock(self, *args)
    def unlockall(self): return _exodus.var_unlockall(self)
    def read(self, *args): return _exodus.var_read(self, *args)
    def readv(self, *args): return _exodus.var_readv(self, *args)
    def write(self, *args): return _exodus.var_write(self, *args)
    def writev(self, *args): return _exodus.var_writev(self, *args)
    def deleterecord(self, *args): return _exodus.var_deleterecord(self, *args)
    def updaterecord(self, *args): return _exodus.var_updaterecord(self, *args)
    def insertrecord(self, *args): return _exodus.var_insertrecord(self, *args)
    def xlate(self, *args): return _exodus.var_xlate(self, *args)
    def sqlexec(self, *args): return _exodus.var_sqlexec(self, *args)
    def version(self): return _exodus.var_version(self)
var_swigregister = _exodus.var_swigregister
var_swigregister(var)
cvar = _exodus.cvar
mvtypemask = cvar.mvtypemask


def MVeq(*args):
  return _exodus.MVeq(*args)
MVeq = _exodus.MVeq

def MVadd(*args):
  return _exodus.MVadd(*args)
MVadd = _exodus.MVadd

def MVmul(*args):
  return _exodus.MVmul(*args)
MVmul = _exodus.MVmul

def MVdiv(*args):
  return _exodus.MVdiv(*args)
MVdiv = _exodus.MVdiv

def MVmod(*args):
  return _exodus.MVmod(*args)
MVmod = _exodus.MVmod

def MVcat(*args):
  return _exodus.MVcat(*args)
MVcat = _exodus.MVcat

def __lshift__(*args):
  return _exodus.__lshift__(*args)
__lshift__ = _exodus.__lshift__
class dim(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, dim, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, dim, name)
    __repr__ = _swig_repr
    def redim(self, *args): return _exodus.dim_redim(self, *args)
    def unparse(self): return _exodus.dim_unparse(self)
    def __call__(self, *args): return _exodus.dim___call__(self, *args)
    __swig_destroy__ = _exodus.delete_dim
    __del__ = lambda self : None;
    def __init__(self, *args): 
        this = _exodus.new_dim(*args)
        try: self.this.append(this)
        except: self.this = this
    def parse(self, *args): return _exodus.dim_parse(self, *args)
    def read(self, *args): return _exodus.dim_read(self, *args)
    def write(self, *args): return _exodus.dim_write(self, *args)
dim_swigregister = _exodus.dim_swigregister
dim_swigregister(dim)

def MVlt(*args):
  return _exodus.MVlt(*args)
MVlt = _exodus.MVlt

def __eq__(*args):
  return _exodus.__eq__(*args)
__eq__ = _exodus.__eq__

def __ne__(*args):
  return _exodus.__ne__(*args)
__ne__ = _exodus.__ne__

def __lt__(*args):
  return _exodus.__lt__(*args)
__lt__ = _exodus.__lt__

def __ge__(*args):
  return _exodus.__ge__(*args)
__ge__ = _exodus.__ge__

def __gt__(*args):
  return _exodus.__gt__(*args)
__gt__ = _exodus.__gt__

def __le__(*args):
  return _exodus.__le__(*args)
__le__ = _exodus.__le__

def __add__(*args):
  return _exodus.__add__(*args)
__add__ = _exodus.__add__

def __sub__(*args):
  return _exodus.__sub__(*args)
__sub__ = _exodus.__sub__

def __mul__(*args):
  return _exodus.__mul__(*args)
__mul__ = _exodus.__mul__

def __div__(*args):
  return _exodus.__div__(*args)
__div__ = _exodus.__div__

def __mod__(*args):
  return _exodus.__mod__(*args)
__mod__ = _exodus.__mod__

def __xor__(*args):
  return _exodus.__xor__(*args)
__xor__ = _exodus.__xor__

SLASH_IS_BACKSLASH = _exodus.SLASH_IS_BACKSLASH

def output(*args):
  return _exodus.output(*args)
output = _exodus.output

def outputl(*args):
  return _exodus.outputl(*args)
outputl = _exodus.outputl

def outputt(*args):
  return _exodus.outputt(*args)
outputt = _exodus.outputt

def errput(*args):
  return _exodus.errput(*args)
errput = _exodus.errput

def errputl(*args):
  return _exodus.errputl(*args)
errputl = _exodus.errputl

def logput(*args):
  return _exodus.logput(*args)
logput = _exodus.logput

def logputl(*args):
  return _exodus.logputl(*args)
logputl = _exodus.logputl

def backtrace():
  return _exodus.backtrace()
backtrace = _exodus.backtrace

def getenvironmentn():
  return _exodus.getenvironmentn()
getenvironmentn = _exodus.getenvironmentn

def setenvironmentn(*args):
  return _exodus.setenvironmentn(*args)
setenvironmentn = _exodus.setenvironmentn

def getprocessn():
  return _exodus.getprocessn()
getprocessn = _exodus.getprocessn

def getexecpath():
  return _exodus.getexecpath()
getexecpath = _exodus.getexecpath
class MVException(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, MVException, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, MVException, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _exodus.new_MVException(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_setmethods__["description"] = _exodus.MVException_description_set
    __swig_getmethods__["description"] = _exodus.MVException_description_get
    if _newclass:description = _swig_property(_exodus.MVException_description_get, _exodus.MVException_description_set)
    __swig_destroy__ = _exodus.delete_MVException
    __del__ = lambda self : None;
MVException_swigregister = _exodus.MVException_swigregister
MVException_swigregister(MVException)
FM = cvar.FM
VM = cvar.VM
SM = cvar.SM
SVM = cvar.SVM
TM = cvar.TM
STM = cvar.STM
SSTM = cvar.SSTM
IM = cvar.IM
RM = cvar.RM
AM = cvar.AM
DQ = cvar.DQ
SQ = cvar.SQ
SLASH = cvar.SLASH
SLASH_ = cvar.SLASH_
LOWERCASE_ = cvar.LOWERCASE_
UPPERCASE_ = cvar.UPPERCASE_
PLATFORM_ = cvar.PLATFORM_

class MVDivideByZero(MVException):
    __swig_setmethods__ = {}
    for _s in [MVException]: __swig_setmethods__.update(getattr(_s,'__swig_setmethods__',{}))
    __setattr__ = lambda self, name, value: _swig_setattr(self, MVDivideByZero, name, value)
    __swig_getmethods__ = {}
    for _s in [MVException]: __swig_getmethods__.update(getattr(_s,'__swig_getmethods__',{}))
    __getattr__ = lambda self, name: _swig_getattr(self, MVDivideByZero, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _exodus.new_MVDivideByZero(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _exodus.delete_MVDivideByZero
    __del__ = lambda self : None;
MVDivideByZero_swigregister = _exodus.MVDivideByZero_swigregister
MVDivideByZero_swigregister(MVDivideByZero)

class MVNonNumeric(MVException):
    __swig_setmethods__ = {}
    for _s in [MVException]: __swig_setmethods__.update(getattr(_s,'__swig_setmethods__',{}))
    __setattr__ = lambda self, name, value: _swig_setattr(self, MVNonNumeric, name, value)
    __swig_getmethods__ = {}
    for _s in [MVException]: __swig_getmethods__.update(getattr(_s,'__swig_getmethods__',{}))
    __getattr__ = lambda self, name: _swig_getattr(self, MVNonNumeric, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _exodus.new_MVNonNumeric(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _exodus.delete_MVNonNumeric
    __del__ = lambda self : None;
MVNonNumeric_swigregister = _exodus.MVNonNumeric_swigregister
MVNonNumeric_swigregister(MVNonNumeric)

class MVOutOfMemory(MVException):
    __swig_setmethods__ = {}
    for _s in [MVException]: __swig_setmethods__.update(getattr(_s,'__swig_setmethods__',{}))
    __setattr__ = lambda self, name, value: _swig_setattr(self, MVOutOfMemory, name, value)
    __swig_getmethods__ = {}
    for _s in [MVException]: __swig_getmethods__.update(getattr(_s,'__swig_getmethods__',{}))
    __getattr__ = lambda self, name: _swig_getattr(self, MVOutOfMemory, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _exodus.new_MVOutOfMemory(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _exodus.delete_MVOutOfMemory
    __del__ = lambda self : None;
MVOutOfMemory_swigregister = _exodus.MVOutOfMemory_swigregister
MVOutOfMemory_swigregister(MVOutOfMemory)

class MVUnassigned(MVException):
    __swig_setmethods__ = {}
    for _s in [MVException]: __swig_setmethods__.update(getattr(_s,'__swig_setmethods__',{}))
    __setattr__ = lambda self, name, value: _swig_setattr(self, MVUnassigned, name, value)
    __swig_getmethods__ = {}
    for _s in [MVException]: __swig_getmethods__.update(getattr(_s,'__swig_getmethods__',{}))
    __getattr__ = lambda self, name: _swig_getattr(self, MVUnassigned, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _exodus.new_MVUnassigned(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _exodus.delete_MVUnassigned
    __del__ = lambda self : None;
MVUnassigned_swigregister = _exodus.MVUnassigned_swigregister
MVUnassigned_swigregister(MVUnassigned)

class MVUndefined(MVException):
    __swig_setmethods__ = {}
    for _s in [MVException]: __swig_setmethods__.update(getattr(_s,'__swig_setmethods__',{}))
    __setattr__ = lambda self, name, value: _swig_setattr(self, MVUndefined, name, value)
    __swig_getmethods__ = {}
    for _s in [MVException]: __swig_getmethods__.update(getattr(_s,'__swig_getmethods__',{}))
    __getattr__ = lambda self, name: _swig_getattr(self, MVUndefined, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _exodus.new_MVUndefined(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _exodus.delete_MVUndefined
    __del__ = lambda self : None;
MVUndefined_swigregister = _exodus.MVUndefined_swigregister
MVUndefined_swigregister(MVUndefined)

class MVInvalidPointer(MVException):
    __swig_setmethods__ = {}
    for _s in [MVException]: __swig_setmethods__.update(getattr(_s,'__swig_setmethods__',{}))
    __setattr__ = lambda self, name, value: _swig_setattr(self, MVInvalidPointer, name, value)
    __swig_getmethods__ = {}
    for _s in [MVException]: __swig_getmethods__.update(getattr(_s,'__swig_getmethods__',{}))
    __getattr__ = lambda self, name: _swig_getattr(self, MVInvalidPointer, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _exodus.new_MVInvalidPointer(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _exodus.delete_MVInvalidPointer
    __del__ = lambda self : None;
MVInvalidPointer_swigregister = _exodus.MVInvalidPointer_swigregister
MVInvalidPointer_swigregister(MVInvalidPointer)

class MVDBException(MVException):
    __swig_setmethods__ = {}
    for _s in [MVException]: __swig_setmethods__.update(getattr(_s,'__swig_setmethods__',{}))
    __setattr__ = lambda self, name, value: _swig_setattr(self, MVDBException, name, value)
    __swig_getmethods__ = {}
    for _s in [MVException]: __swig_getmethods__.update(getattr(_s,'__swig_getmethods__',{}))
    __getattr__ = lambda self, name: _swig_getattr(self, MVDBException, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _exodus.new_MVDBException(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _exodus.delete_MVDBException
    __del__ = lambda self : None;
MVDBException_swigregister = _exodus.MVDBException_swigregister
MVDBException_swigregister(MVDBException)

class MVNotImplemented(MVException):
    __swig_setmethods__ = {}
    for _s in [MVException]: __swig_setmethods__.update(getattr(_s,'__swig_setmethods__',{}))
    __setattr__ = lambda self, name, value: _swig_setattr(self, MVNotImplemented, name, value)
    __swig_getmethods__ = {}
    for _s in [MVException]: __swig_getmethods__.update(getattr(_s,'__swig_getmethods__',{}))
    __getattr__ = lambda self, name: _swig_getattr(self, MVNotImplemented, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _exodus.new_MVNotImplemented(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _exodus.delete_MVNotImplemented
    __del__ = lambda self : None;
MVNotImplemented_swigregister = _exodus.MVNotImplemented_swigregister
MVNotImplemented_swigregister(MVNotImplemented)

class MVDebug(MVException):
    __swig_setmethods__ = {}
    for _s in [MVException]: __swig_setmethods__.update(getattr(_s,'__swig_setmethods__',{}))
    __setattr__ = lambda self, name, value: _swig_setattr(self, MVDebug, name, value)
    __swig_getmethods__ = {}
    for _s in [MVException]: __swig_getmethods__.update(getattr(_s,'__swig_getmethods__',{}))
    __getattr__ = lambda self, name: _swig_getattr(self, MVDebug, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _exodus.new_MVDebug(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _exodus.delete_MVDebug
    __del__ = lambda self : None;
MVDebug_swigregister = _exodus.MVDebug_swigregister
MVDebug_swigregister(MVDebug)

class MVStop(MVException):
    __swig_setmethods__ = {}
    for _s in [MVException]: __swig_setmethods__.update(getattr(_s,'__swig_setmethods__',{}))
    __setattr__ = lambda self, name, value: _swig_setattr(self, MVStop, name, value)
    __swig_getmethods__ = {}
    for _s in [MVException]: __swig_getmethods__.update(getattr(_s,'__swig_getmethods__',{}))
    __getattr__ = lambda self, name: _swig_getattr(self, MVStop, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _exodus.new_MVStop(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _exodus.delete_MVStop
    __del__ = lambda self : None;
MVStop_swigregister = _exodus.MVStop_swigregister
MVStop_swigregister(MVStop)

class MVAbort(MVException):
    __swig_setmethods__ = {}
    for _s in [MVException]: __swig_setmethods__.update(getattr(_s,'__swig_setmethods__',{}))
    __setattr__ = lambda self, name, value: _swig_setattr(self, MVAbort, name, value)
    __swig_getmethods__ = {}
    for _s in [MVException]: __swig_getmethods__.update(getattr(_s,'__swig_getmethods__',{}))
    __getattr__ = lambda self, name: _swig_getattr(self, MVAbort, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _exodus.new_MVAbort(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _exodus.delete_MVAbort
    __del__ = lambda self : None;
MVAbort_swigregister = _exodus.MVAbort_swigregister
MVAbort_swigregister(MVAbort)

class MVArrayDimensionedZero(MVException):
    __swig_setmethods__ = {}
    for _s in [MVException]: __swig_setmethods__.update(getattr(_s,'__swig_setmethods__',{}))
    __setattr__ = lambda self, name, value: _swig_setattr(self, MVArrayDimensionedZero, name, value)
    __swig_getmethods__ = {}
    for _s in [MVException]: __swig_getmethods__.update(getattr(_s,'__swig_getmethods__',{}))
    __getattr__ = lambda self, name: _swig_getattr(self, MVArrayDimensionedZero, name)
    __repr__ = _swig_repr
    def __init__(self): 
        this = _exodus.new_MVArrayDimensionedZero()
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _exodus.delete_MVArrayDimensionedZero
    __del__ = lambda self : None;
MVArrayDimensionedZero_swigregister = _exodus.MVArrayDimensionedZero_swigregister
MVArrayDimensionedZero_swigregister(MVArrayDimensionedZero)

class MVArrayIndexOutOfBounds(MVException):
    __swig_setmethods__ = {}
    for _s in [MVException]: __swig_setmethods__.update(getattr(_s,'__swig_setmethods__',{}))
    __setattr__ = lambda self, name, value: _swig_setattr(self, MVArrayIndexOutOfBounds, name, value)
    __swig_getmethods__ = {}
    for _s in [MVException]: __swig_getmethods__.update(getattr(_s,'__swig_getmethods__',{}))
    __getattr__ = lambda self, name: _swig_getattr(self, MVArrayIndexOutOfBounds, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _exodus.new_MVArrayIndexOutOfBounds(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _exodus.delete_MVArrayIndexOutOfBounds
    __del__ = lambda self : None;
MVArrayIndexOutOfBounds_swigregister = _exodus.MVArrayIndexOutOfBounds_swigregister
MVArrayIndexOutOfBounds_swigregister(MVArrayIndexOutOfBounds)

class MVArrayNotDimensioned(MVException):
    __swig_setmethods__ = {}
    for _s in [MVException]: __swig_setmethods__.update(getattr(_s,'__swig_setmethods__',{}))
    __setattr__ = lambda self, name, value: _swig_setattr(self, MVArrayNotDimensioned, name, value)
    __swig_getmethods__ = {}
    for _s in [MVException]: __swig_getmethods__.update(getattr(_s,'__swig_getmethods__',{}))
    __getattr__ = lambda self, name: _swig_getattr(self, MVArrayNotDimensioned, name)
    __repr__ = _swig_repr
    def __init__(self): 
        this = _exodus.new_MVArrayNotDimensioned()
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _exodus.delete_MVArrayNotDimensioned
    __del__ = lambda self : None;
MVArrayNotDimensioned_swigregister = _exodus.MVArrayNotDimensioned_swigregister
MVArrayNotDimensioned_swigregister(MVArrayNotDimensioned)

# This file is compatible with both classic and new-style classes.


