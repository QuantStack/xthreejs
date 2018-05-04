#ifndef XTHREE_QUATERNION_KEYFRAME_TRACK_HPP
#define XTHREE_QUATERNION_KEYFRAME_TRACK_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "xtensor/xtensor.hpp"
#include "xtensor/xadapt.hpp"

#include "../../base/xenums.hpp"
#include "../../base/xthree_types.hpp"
#include "../xkeyframe_track_autogen.hpp"

namespace xthree
{
    //
    // quaternion_keyframe_track declaration
    //

    template<class D>
    class xquaternion_keyframe_track : public xkeyframe_track<D>
    {
    public:

        using base_type = xkeyframe_track<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



    protected:

        xquaternion_keyframe_track();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using quaternion_keyframe_track = xw::xmaterialize<xquaternion_keyframe_track>;

    using quaternion_keyframe_track_generator = xw::xgenerator<xquaternion_keyframe_track>;

    //
    // quaternion_keyframe_track implementation
    //


    template <class D>
    inline void xquaternion_keyframe_track<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xquaternion_keyframe_track<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xquaternion_keyframe_track<D>::xquaternion_keyframe_track()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xquaternion_keyframe_track<D>::set_defaults()
    {
        this->_model_name() = "QuaternionKeyframeTrackModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xquaternion_keyframe_track));
//}
#endif