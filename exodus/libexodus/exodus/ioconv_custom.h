// generated by exodus "compile ioconv_custom"
//#ifndef EXODUSDLFUNC_IOCONV_CUSTOM_H
#define EXODUSDLFUNC_IOCONV_CUSTOM_H

// a member variable/object to cache a pointer/object for the shared library function
// ExodusFunctorBase efb_ioconv_custom;
class efb_ioconv_custom : public ExodusFunctorBase {
   public:
	efb_ioconv_custom(MvEnvironment& mv)
		: ExodusFunctorBase("ioconv_custom", "exodusprogrambasecreatedelete_", mv) {
	}

	efb_ioconv_custom& operator=(const var& newlibraryname) {
		closelib();
		libraryname_ = newlibraryname.toString();
		return (*this);
	}

	// a member function with the right arguments, returning a var or void
	var operator()(in type, in input, in mode, out output) {

		// first time link to the shared lib and create/cache an object from it
		// passing current standard variables in mv
		// first time link to the shared lib and create/cache an object from it
		// passing current standard variables in mv
		// if (efb_getlang.pmemberfunction_==NULL)
		// efb_getlang.init("getlang","exodusprogrambasecreatedelete_",mv);
		if (this->pmemberfunction_ == NULL)
			this->init();

		// define a function type (pExodusProgramBaseMemberFunction)
		// that can call the shared library object member function
		// with the right arguments and returning a var or void
		using pExodusProgramBaseMemberFunction = var (ExodusProgramBase::*)(in, in, in, out);

		// call the shared library object main function with the right args,
		// returning a var or void
		// return CALLMEMBERFUNCTION(*(efb_ioconv_custom.pobject_),
		//((pExodusProgramBaseMemberFunction) (efb_ioconv_custom.pmemberfunction_)))
		// (mode);
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcast-function-type"
		return CALLMEMBERFUNCTION(*(this->pobject_),
								  ((pExodusProgramBaseMemberFunction)(
									  this->pmemberfunction_)))(type, input, mode, output);
#pragma GCC diagnostic pop
	}

	var operator()() {
		var type_in;
		var input_in;
		var mode_in;
		var output_out;
		return operator()(type_in, input_in, mode_in, output_out);
	}

	var operator()(in type) {
		var input_in;
		var mode_in;
		var output_out;
		return operator()(type, input_in, mode_in, output_out);
	}

	var operator()(in type, in input) {
		var mode_in;
		var output_out;
		return operator()(type, input, mode_in, output_out);
	}

	var operator()(in type, in input, in mode) {
		var output_out;
		return operator()(type, input, mode, output_out);
	}
};
efb_ioconv_custom ioconv_custom{mv};
//#endif
