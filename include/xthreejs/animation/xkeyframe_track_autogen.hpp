#ifndef XTHREE_KEYFRAME_TRACK_HPP
#define XTHREE_KEYFRAME_TRACK_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../base/xthree.hpp"
#include "../base/xrender.hpp"

namespace xthree
{
    //
    // keyframe_track declaration
    //

    template<class D>
    class xkeyframe_track : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(std::string, derived_type, name, "");
        XPROPERTY(webgldataunion<float>, derived_type, times);
        XPROPERTY(webgldataunion<float>, derived_type, values);
        XPROPERTY(std::string, derived_type, interpolation, "InterpolateLinear", xenums::InterpolationModes);

        const std::vector<xw::xjson_path_type>& buffer_paths() const;

        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xkeyframe_track();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using keyframe_track = xw::xmaterialize<xkeyframe_track>;

    using keyframe_track_generator = xw::xgenerator<xkeyframe_track>;

    //
    // keyframe_track implementation
    //

    template <class D>
    inline const std::vector<xw::xjson_path_type>&  xkeyframe_track<D>::buffer_paths() const
    {
        static const std::vector<xw::xjson_path_type> default_buffer_paths = { 
            { "times", "buffer" },
            { "values", "buffer" },
        };
        return default_buffer_paths;
    }

    template <class D>
    inline void xkeyframe_track<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(name, state, buffers);
        xw::set_patch_from_property(times, state, buffers);
        xw::set_patch_from_property(values, state, buffers);
        xw::set_patch_from_property(interpolation, state, buffers);
    }

    template <class D>
    inline void xkeyframe_track<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(name, patch, buffers);
        xw::set_property_from_patch(times, patch, buffers);
        xw::set_property_from_patch(values, patch, buffers);
        xw::set_property_from_patch(interpolation, patch, buffers);
    }

    template <class D>
    inline xkeyframe_track<D>::xkeyframe_track()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xkeyframe_track<D>::set_defaults()
    {
        this->_model_name() = "KeyframeTrackModel";
        this->_view_name() = "";
    }
}

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xkeyframe_track>& widget);

/*********************
 * precompiled types *
 *********************/

#ifdef XTHREEJS_PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xkeyframe_track>;
        extern template xw::xmaterialize<xthree::xkeyframe_track>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xkeyframe_track>>;
        extern template class xw::xgenerator<xthree::xkeyframe_track>;
        extern template xw::xgenerator<xthree::xkeyframe_track>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xkeyframe_track>>;
    #endif
#endif

#endif