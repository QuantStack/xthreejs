#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xstring_keyframe_track>;
template xw::xmaterialize<xthree::xstring_keyframe_track>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xstring_keyframe_track>>;
template class xw::xgenerator<xthree::xstring_keyframe_track>;
template xw::xgenerator<xthree::xstring_keyframe_track>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xstring_keyframe_track>>;