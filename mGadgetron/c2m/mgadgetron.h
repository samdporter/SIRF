#ifndef CGADGETRON_TO_MATLAB_INTERFACE
#define CGADGETRON_TO_MATLAB_INTERFACE

#define CGADGETRON_FOR_MATLAB
#include "shrhelp.h"

#ifndef CGADGETRON_FOR_MATLAB
extern "C" {
#endif
EXPORTED_FUNCTION  void* mGT_newObject(const char* name);
EXPORTED_FUNCTION 	void* mGT_parameter(void* ptr, const char* obj, const char* name);
EXPORTED_FUNCTION 	void* mGT_CoilSensitivities(const char* file);
EXPORTED_FUNCTION 	void* mGT_computeCoilSensitivities(void* ptr_csms, void* ptr_acqs);
EXPORTED_FUNCTION 	void* mGT_AcquisitionModel(const void* ptr_acqs, const void* ptr_imgs);
EXPORTED_FUNCTION 	void* mGT_setCSMs(void* ptr_am, const void* ptr_csms);
EXPORTED_FUNCTION 	void* mGT_AcquisitionModelForward(void* ptr_am, const void* ptr_imgs);
EXPORTED_FUNCTION 	void* mGT_AcquisitionModelBackward(void* ptr_am, const void* ptr_acqs);
EXPORTED_FUNCTION 	void* mGT_ISMRMRDAcquisitionsFromFile(const char* file);
EXPORTED_FUNCTION 	void* mGT_ISMRMRDAcquisitionsFile(const char* file);
EXPORTED_FUNCTION 	void* mGT_processAcquisitions(void* ptr_proc, void* ptr_input);
EXPORTED_FUNCTION 	void* mGT_acquisitionFromContainer(void* ptr_acqs, unsigned int acq_num);
EXPORTED_FUNCTION 	void* mGT_orderAcquisitions(void* ptr_acqs);
EXPORTED_FUNCTION 	void* mGT_reconstructImages(void* ptr_recon, void* ptr_input);
EXPORTED_FUNCTION 	void* mGT_reconstructedImages(void* ptr_recon);
EXPORTED_FUNCTION 	void* mGT_processImages(void* ptr_proc, void* ptr_input);
EXPORTED_FUNCTION 	void* mGT_imagesCopy(const void* ptr_imgs);
EXPORTED_FUNCTION 	void* mGT_writeImages (void* ptr_imgs, const char* out_file, const char* out_group);
EXPORTED_FUNCTION 	void* mGT_imageWrapFromContainer(void* ptr_imgs, unsigned int img_num);
#ifndef CGADGETRON_FOR_MATLAB
EXPORTED_FUNCTION 	void mGT_getCSMDimensions(void* ptr_csms, int csm_num, size_t ptr_dim);
EXPORTED_FUNCTION 	void mGT_getCSMData(void* ptr_csms, int csm_num, size_t ptr_re, size_t ptr_im);
EXPORTED_FUNCTION 	void mGT_getCSMDataAbs(void* ptr_csms, int csm_num, size_t ptr);
EXPORTED_FUNCTION 	void mGT_getImageDimensions(void* ptr_imgs, int img_num, size_t ptr_dim);
EXPORTED_FUNCTION 	void mGT_getImageDataAsDoubleArray (void* ptr_imgs, int img_num, size_t ptr_data);
EXPORTED_FUNCTION 	void mGT_getImageDataAsComplexArray (void* ptr_imgs, int img_num, size_t ptr_data);
#else
EXPORTED_FUNCTION 	void mGT_getCSMDimensions(void* ptr_csms, int csm_num, int* dim);
EXPORTED_FUNCTION 	void mGT_getCSMData(void* ptr_csms, int csm_num, double* re, double* im);
EXPORTED_FUNCTION 	void mGT_getCSMDataAbs(void* ptr_csms, int csm_num, double* v);
EXPORTED_FUNCTION 	void mGT_getImageDimensions(void* ptr_imgs, int img_num, int* dim);
EXPORTED_FUNCTION 	void mGT_getImageDataAsDoubleArray(void* ptr_imgs, int img_num, double* data);
EXPORTED_FUNCTION 	void mGT_getImageDataAsCmplxArray (void* ptr_imgs, int img_num, double* re, double* im);
#endif
EXPORTED_FUNCTION 	void* mGT_dataItems(const void* ptr_x);
EXPORTED_FUNCTION 	void* mGT_norm(const void* ptr_x);
EXPORTED_FUNCTION 	void* mGT_dot(const void* ptr_x, const void* ptr_y);
EXPORTED_FUNCTION 	void* mGT_axpby( double ar, double ai, const void* ptr_x, double br, double bi, const void* ptr_y);
EXPORTED_FUNCTION 	void* mGT_addReader(void* ptr_gc, const char* id, const void* ptr_r);
EXPORTED_FUNCTION 	void* mGT_addWriter(void* ptr_gc, const char* id, const void* ptr_r);
EXPORTED_FUNCTION 	void* mGT_addGadget(void* ptr_gc, const char* id, const void* ptr_r);
EXPORTED_FUNCTION 	void* mGT_setGadgetProperty(void* ptr_g, const char* prop, const char* value);
EXPORTED_FUNCTION 	void* mGT_configGadgetChain(void* ptr_con, void* ptr_gc);
EXPORTED_FUNCTION 	void* mGT_registerHDFReceiver (void* ptr_con, const char* file, const char* group);
EXPORTED_FUNCTION 	void* mGT_registerImagesReceiver(void* ptr_con, void* ptr_img);
EXPORTED_FUNCTION 	void* mGT_setConnectionTimeout(void* ptr_con, unsigned int timeout_ms);
EXPORTED_FUNCTION 	void* mGT_connect(void* ptr_con, const char* host, const char* port);
EXPORTED_FUNCTION 	void* mGT_sendConfigScript(void* ptr_con, const char* config);
EXPORTED_FUNCTION 	void* mGT_sendConfigFile(void* ptr_con, const char* file);
EXPORTED_FUNCTION 	void* mGT_sendParameters(void* ptr_con, const void* par);
EXPORTED_FUNCTION 	void* mGT_sendParametersString(void* ptr_con, const char* par);
EXPORTED_FUNCTION 	void* mGT_sendAcquisitions(void* ptr_con, void* ptr_dat);
EXPORTED_FUNCTION 	void* mGT_sendImages(void* ptr_con, void* ptr_img);
EXPORTED_FUNCTION 	void* mGT_disconnect(void* ptr_con);
#ifndef CGADGETRON_FOR_MATLAB
}
#endif


#endif
