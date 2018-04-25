#ifndef XTHREE_BOOLEAN_KEYFRAME_TRACK_HPP
#define XTHREE_BOOLEAN_KEYFRAME_TRACK_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "../../base/xenums.hpp"
#include "../../base/xthree_types.hpp"
#include "../xkeyframe_track_autogen.hpp"

namespace xthree
{
    //
    // boolean_keyframe_track declaration
    //

    template<class D>
    class xboolean_keyframe_track : public xkeyframe_track<D>
    {
    public:

        using base_type = xkeyframe_track<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);


    protected:

        xboolean_keyframe_track();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using boolean_keyframe_track = xw::xmaterialize<xboolean_keyframe_track>;

    using boolean_keyframe_track_generator = xw::xgenerator<xboolean_keyframe_track>;

    //
    // boolean_keyframe_track implementation
    //

    template <class D>
    inline void xboolean_keyframe_track<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xboolean_keyframe_track<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xboolean_keyframe_track<D>::xboolean_keyframe_track()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xboolean_keyframe_track<D>::set_defaults()
    {
        this->_model_name() = "BooleanKeyframeTrackModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xboolean_keyframe_track));
//}
#endif